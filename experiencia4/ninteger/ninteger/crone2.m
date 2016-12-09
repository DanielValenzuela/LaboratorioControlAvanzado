function C = crone2(w, gain, phase, n, w1)

% C = crone2(w, gain, phase, n)
% or
% C = crone2(w, [], phase, n, w1)
% This function reckons the parameters of
% a variable phase frequency domain non-integer controller.
% Desired gain in dB and phase in degrees are given
% in variables gain and phase for frequencies specified in w rad/s.
% n is the desired number of zeros and poles of the controller;
% it may be ommited (in the first syntax) or given as [],
% but, if given, may be slightly changed by the algorithm.
% If no specification on gain is desired let that variable be []
% and give in the last variable a frequency w1 rad/s
% where the controller is to have gain 1 (or 0 dB);
% in that case all zeros and poles are returned stable.
% Duarte Valério 2003

if nargin < 4 | isempty(n)
    n = length(w);
end
if size(phase,2) > size(phase,1)
    phase = phase';
end

% zero and pole frequencies are found
wzp = resolution(w, -deg2rad(phase), n);

% First filter - the following wi are neglected:
% * very big ones (having a frequency three decades or more greater than max(w))
% * complex ones lying outside interest frequency range
temp = [];
for i = 1:length(wzp)
    if (isreal(wzp(i)) & abs(wzp(i))<max(w)*100) |...
            (~isreal(wzp(i)) & abs(wzp(i))<max(w) & abs(wzp(i))>min(w))
        temp = [temp wzp(i)];
    end
end
wzp = temp;

% Second filter - values of wi having similar effects in phase are neglected
tolerance = deg2rad(1);
flags = [];
for i = 1:length(wzp)-1
    for j = i+1:length(wzp)
        if abs(angle(wzp(i)) + angle(wzp(j)) - pi) < tolerance &...
                abs(abs(wzp(i)) - abs(wzp(j))) < tolerance
            flags = [flags i j];
        end
    end
end
wzp = wzp(setdiff(1:length(wzp), flags));

% Third filter - sudden 180º phase changes are searched for
C = zpk([],wzp,1);
[gm, phm] = bode(C, w);
phm = squeeze(phm);
flags = [];
for i = 1:length(w)-1 % if phase of C changes but phase does not...
    if abs((phm(i)-phm(i+1)) / (phase(i)-phase(i+1))) > 1.5
        for j = 1:length(wzp)
            if abs(wzp(j))>w(i) & abs(wzp(j))<w(i+1) & imag(wzp(j))~=0
                flags = [flags j];
            end
        end
    end
end
wzp = wzp(setdiff(1:length(wzp), flags));

% if no desired gain was provided, each wzp(i) is checked
% to see if it should be a stable pole or a stable zero
if isempty(gain)
    wz=[];
    wp=[];
    for i=1:length(wzp)
        if real(wzp(i))>0
            wp=[wp -wzp(i)];
        else
            wz=[wz wzp(i)];
        end
    end
% if a desired gain was provided, each wi is tested
% as pole or zero to check for the better gain fit
else
    N = length(wzp);
    gainM = gain - mean(gain);
    error = inf;
    for i = 0:2^N-1 % all combinations are tested
        config = dec2bin(i,N);
        wztemp = [];
        wptemp = [];
        for i = 1:N
            if eval(config(i)) % 1 means a pole, 0 means a zero
                wptemp = [wptemp -wzp(i)];
            else
                wztemp = [wztemp wzp(i)];
            end
        end
        if imag(sum(wptemp)) == 0 % or: if imag(sum(wztemp))==0
            gainT = 20*log10(squeeze(bode(zpk(wztemp,wptemp,1), w)));
            gainT = gainT - mean(gainT);
            errortemp = sum((gainT - gainM).^2);
            if errortemp < error % if this attempt's gain error is the smaller until now...
                error = errortemp;
                wz = wztemp;
                wp = wptemp;
            end
        end
    end
end

% phase correction is checked
C = zpk(wz, wp, 1);
[gm, phm] = bode(C, w);
error = squeeze(phm) - phase;
difference=round(mean(error/90));
if difference < 0
    wz = [wz zeros(1,abs(difference))];
end
if difference > 0
    wp = [wp zeros(1,abs(difference))];
end

if isempty(gain)
    % if no desired gain was provided, gain is reckoned
    k = 1 / bode(zpk(wz,wp,1), w1);
else
    % if a desired gain was provided, static gain is reckoned
    % (imaginary part is always zero, but may have a residual value)
    k = real(mean(10.^((gain - 20*log10(squeeze(bode(zpk(wz,wp,1), w))))/20)));
end

% the controller is built
C = tf(zpk(wz, wp, k));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function wzp = resolution(w, phase, M)

% This function solves the system of equations necessary for crone2.
% M is the number of variables; N is the number of
% phase sampling points (and thus the number of equations).
% Duarte Valério 2003

N=length(w);

% the first system of equations is solved
A = tan(phase);
Y = w/w(1);
X = zeros(N,M); % this was zeros(N) in v. 2.0; that was an ERROR!
for i = 1:N % N is the number of sampling frequencies (number of equations)
    for j = 0:floor((M-1)/2) % M is the number of variables (frequencies to find)
        X(i,2*j+1) = ((-1)^j) * (Y(i)^(2*j+1));
    end
    for j = 1:floor(M/2)
        X(i,2*j) = -A(i) * ((-1)^j) * (Y(i)^(2*j));
    end
end
s = X\A;
ndigits = 10;
while (max(abs(X*s-A))>deg2rad(1) | ismember(NaN,s) | max(isinf(s))) & ndigits<100
    ndigits = ndigits+5;
    s = resmaple(X,A,ndigits);
end
if max(abs(X*s-A))>deg2rad(1) | ismember(NaN,s) | max(isinf(s))
    warning('A reliable solution for frequency calculations could not be found.')
end
s = [1; s]; % indexes should vary from 0 up to M, but they vary from 1 up to 1+M

% the second system of equations is solved
sistem = [];
for i = 0:M
    system(M-i+1) = ((-1)^i) * s(i+1);
    % indexes should vary from 0 up to M, but they vary from 1 up to 1+M
end
x = roots(system(end:-1:1));
% the polynomial must have the independent coefficient at the end

% the third system of equations is solved
wzp = [];
for i = 1:length(x)
    if x(i) ~= 0
        wzp = [wzp; w(1)/x(i)];
    end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function s = resmaple(X, A, ndigits)

% Function to solve the linear system X*s=A,
% that may be overdetermined, consistent or underdetermined.
% Maple is used and ndigits correct digits are assured.

maple(strcat('Digits:=',num2str(ndigits)));
s = maple('linsolve',X,A);
% if no solution was found, the problem is checked to see if it is overdetermined
if isempty(s)
    maple('X:=',X);
    maple('A:=',A);
    S = eval(sym(maple('evalf(Svd(X,U,V))')));
    c = eval(sym(maple('multiply(transpose(U),A)')));
    maple('y:=',c./S');
    s = maple('multiply(V,y)');
end
% if there is still no solution
if isempty(s)
    s = [];
else
    % if there is more than one solution...
    if ismember('_',s)
        s = strrep(s, '_t', 't'); % all '_t' are replaced by 't'
        s = strrep(s, '[', '('); % all '[' are replaced by '('
        s = strrep(s, ']', ')'); % all ']' are replaced by ')'
        s = strrep(s, ')(', ','); % all '][' are replaced by ','
        if ~isempty(findstr(s, 'matrix'))
            % proper syntax of matrix is restored
            s = strrep(s, 'matrix((', 'matrix([');
            s(end-1) = ']';
        end
        % a value is given to variable t so that we may
        % proceed as though there was only one solution
        t = ones(max(size(X)));
    end
    % if there is only one solution...
    s = eval(sym(s));
    if size(s, 2) > size(s, 1)
        s = s';
    end
end