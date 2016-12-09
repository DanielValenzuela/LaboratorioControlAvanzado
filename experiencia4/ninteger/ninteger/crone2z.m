function C = crone2z(w, gain, phase, n, Ts, w1)

% C = crone2z(w, gain, phase, n, Ts)
% or
% C = crone2z(w, [], phase, n, Ts, w1)
% This function reckons the parameters of
% a variable phase frequency domain non-integer controller.
% Desired gain in dB and phase in degrees are given
% in variables gain and phase for frequencies specified in w rad/s.
% n is the desired number of delays of the controller,
% which may be set to [] or [n1 n2]; Ts is the sampling time in seconds.
% If no specification on gain is desired let that variable be []
% and give in the last variable a frequency w1 rad/s
% where the controller is to have gain 1 (or 0 dB).
% Duarte Valério 2003

if isempty(n)
   n = length(w);
end
temp = [];
if length(n) == 1 % only the total number of poles and zeros is given
    for ordnum = 1:n+1
        [coef, J] = fminsearch(@crone2zAux, ones(1, n+2),...
            optimset('Display','off'), w, gain, phase, ordnum, Ts);
        temp(ordnum).coef = coef;
        temp(ordnum).J = J;
    end
    [J, ordnum] = min([temp.J]);
    coef = temp(ordnum).coef;
    [C1, J1] = crone2zExact(w, phase, n, Ts);
    [C2, J2] = crone2zExact(w, phase, -n, Ts);
else % a specific combination of poles and zeros is given
    ordnum = n(1)+1;
    [coef, J] = fminsearch(@crone2zAux, ones(1, sum(n)+2),...
        optimset('Display','off'), w, gain, phase, ordnum, Ts);
    if n(2) == 0
        [C1, J1] = crone2zExact(w, phase, n(1), Ts);
        J2 = inf;
    elseif n(1) == 0
        J1 = inf;
        [C2, J2] = crone2zExact(w, phase, -n(2), Ts);
    else
        J1 = inf;
        J2 = inf;
    end
end
if min([J J1 J2]) == J % the best option has both poles and zeros
    C = tf(coef(1:ordnum), coef(1+ordnum:end), Ts, 'Variable', 'z^-1');
elseif min([J J1 J2]) == J1 % the best option has zeros but no poles
    C = C1;
else % the best option has poles but no zeros
    C = C2;
end
if nargin == 6
    C = C / bode(C, w1);
else
    C = C * mean(10 .^ (gain/20)) / mean(squeeze(bode(C, w)));
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function J = crone2zAux(coef, w, gain, ph, ordnum, Ts)

% This function returns an index of performance
% of the transfer function with the coefficients it receives.
% The first ordnum are from the numerator, the remaining from the denominator.

ordden = length(coef) - ordnum;
tempnum = 0;
for k = 0:ordnum-1 % indexes should begin with 0, but as they don't we must...
   tempnum = tempnum + coef(k+1) * exp(-j*k*w*Ts); % ...add 1 when accessing vector coef
end
tempden = 0;
for k = 0:ordden-1 % indexes should begin with 0, but as they don't we must...
   tempden = tempden + coef(ordnum+k+1) * exp(-j*k*w*Ts); % ...add 1 when accessing vector coef
end
if isempty(gain)
    try
        J = norm(rad2deg(phase(tempnum ./ tempden)) - ph);
    catch
        J = norm(rad2deg(angle(tempnum ./ tempden)) - ph);
    end
else
    temp = 20 * log10(abs(tempnum ./ tempden));
    J = norm(rad2deg(phase(tempnum ./ tempden)) - ph) +...
        norm((temp - mean(temp)) - (gain - mean(gain)));
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [C, J] = crone2zExact(w, phase, M, Ts)

% [C, J] = crone2zExact(w, phase, M, Ts)
% This function reckons the parameters of
% a variable phase frequency domain non-integer controller,
% that may be either a FIR filter or a filter with poles but no zeros.
% Desired phase in degrees is given in variable phase
% for frequencies specified in w rad/s.
% M is the desired number of delays of the controller,
% positive for a FIR filter and negative for a filter with poles but no zeros.
% Ts is the sampling time in seconds.
% Duarte Valério 2003

type = sign(M); % 1: C is a FIR filter; -1: C has poles but no zeros
M = abs(M);
if size(phase,2) > size(phase,1)
    phase = phase';
end
if size(w,2) > size(w,1)
    w = w';
end

c = resolution(w, deg2rad(phase), M, type);

% the controller is built
z = tf('z',Ts);
C = 1;
if type < 0
   for i = 1:M
      C = C / (1 - c(i)*z^-1);
   end
else
   for i = 1:M
      C = C * (1 - c(i)*z^-1);
   end
end
C.Variable = 'z^-1';

% the index of performance is returned

[gC, phC] = bode(C, w);
J = norm(rad2deg(squeeze(phC)) - phase);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function c = resolution(w, phase, M, type)

% This function solves the system of equations necessary for crone2.
% M is the number of variables; N is the number of
% phase sampling points (and thus the number of equations).
% Duarte Valério 2003

N = size(w,1);

% the first system of equations is solved
if type > 0
   Phi = tan(phase - M*pi/2);
else
   Phi = tan(-phase - M*pi/2);
end
for k = 1:ceil(M/2)
   Phi = [Phi ones(N,1) Phi(:,1)];
end % the first column corresponds to column 0 in formulas
A = sin(w(1)) ./ sin(w);
B = cos(w(1)) ./ sin(w) - cot(w);
X = zeros(N,M);
D = -Phi(:,1);
for k = 1:M
   D = D - (-1)^floor(k/2) * Phi(:,k+1) * total(k-1, M-k+1) .* B.^k;
   for r = 1:k
      X(:,r) = X(:,r) +...
         (-1)^floor(k/2) * Phi(:,k+1) * total(k-r-1, M-k+1) .* A.^r .* B.^(k-r);
   end
end
s = X\D;
if max(abs(X*s-D))>deg2rad(1) | ismember(NaN,s) | max(isinf(s))
   s = pinv(X)*D;
end
ndigits = 10;
try
   while (max(abs(X*s-D))>deg2rad(1) | ismember(NaN,s) | max(isinf(s))) & ndigits<100
      ndigits = ndigits+5;
      s = resmaple(X,D,ndigits);
   end
catch
   s = pinv(X)*D;
end
if max(abs(X*s-D))>deg2rad(1) | ismember(NaN,s) | max(isinf(s))
   warning('A reliable solution for frequency calculations could not be found.')
end
s = [1; s]; % indexes should vary from 0 up to M, but they vary from 1 up to 1+M

% the second system of equations is solved
system = [];
for i = 0:M
   system(M-i+1) = ((-1)^i) * s(i+1);
   % indexes should vary from 0 up to M, but they vary from 1 up to 1+M
end
x = roots(system(end:-1:1));
% the polynomial must have the independent coefficient at the end

% the third system of equations is solved
c = [];
for k = 1:length(x)
   c = [c; 1/(sin(w(1))*(x(k) + 1/tan(w(1))))];
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
   try
      maple('X:=',X);
      maple('A:=',A);
      S = eval(sym(maple('evalf(Svd(X,U,V))')));
      c = eval(sym(maple('multiply(transpose(U),A)')));
      maple('y:=',c./S');
      s = maple('multiply(V,y)');
   end
end
% if there is still no solution
if isempty(s)
   s = [];
else
   % if there is more than one solution
   if ismember('_',s)
      % underscores (_) and indexes ([1]) after the t are done away with
      flags = [];
      for i = 1:length(s)-4
         if s(i) == '_'
            flags = [flags i i+2 i+3 i+4];
         end
      end
      s = s(setdiff(1:length(s),flags));
      % strings t[n] are changed into t(n), where n is a natural
      inside = 0;
      maxdep = 0;
      temp = [];
      for i = 1:length(s)-1
         if s(i)=='t'
            s(i+1) = '(';
            inside = 1;
         end
         if inside==1 & s(i)~='t' & s(i)~='(' & s(i)~=']'
            temp = [temp s(i)];
         end
         if inside==1 & s(i)==']'
            s(i) = ')';
            inside = 0;
            maxdep = max(maxdep,eval(temp));
            temp = [];
         end
      end
      % a value is given to variables so that one may
      % proceed as though there were only one solution
      t = ones(1,maxdep);
   end
   % if there is only one solution
   s = eval(sym(s));
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function t = total(b,a)

if b < 0
   t = 1;
else
   t = 0;
   for i = 1:a
      t = t + total(b-1,i);
   end
end