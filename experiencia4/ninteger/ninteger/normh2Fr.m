function [H2, status] = normh2Fr (F, Q, problems)

% function [H2, status] = normh2Fr (F, Q, problems)
% The H2 norm of transfer function F, commensurate of order Q, is found
% using Malti's method. (Example: 1/(s^.5-1) is handled as
% normh2Fr(tf(1, [1 -1]), 0.5).) If Q is ommited, 1 is assumed.
% Variable problems handles unstable and non-causal systems as follows:
% 'none' - no warnings or errors are given
% 'warnings' - warnings are given (this is the default)
% 'errors' - errors are given
% Variable status is [0 0] if the system is ok; the first position is 1
% if the system is unstable; the second is 1 if the system is not causal. 
% Duarte Valério 2004

if nargin < 3 | (strcmp(problems, 'errors') & strcmp(problems, 'none'))
    problems = 'warnings';
end
if nargin < 2 | isempty(Q)
    Q = 1;
end
F = tf(F);
H2square = 0;
status = [0 0];
for m = 1:size(F,1) % reducing the problems to SISO plants...
    for n = 1:size(F,2)
        [H2squaretemp, statustemp] = H2FrSISO(F(m,n), Q, problems);
        H2square = H2square + H2squaretemp;
        status = status | statustemp;
    end
end
H2 = sqrt(H2square);
if abs(angle(H2)) < 1e-3 % if there is a neglectable imaginary part...
    H2 = real(H2);
else
    if strcmp(problems, 'errors')
        error('A non-sensical imaginary number was obtained.')
    elseif strcmp(problems, 'warnings')
        warning('A non-sensical imaginary number was obtained.')
    end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [H2square, status] = H2FrSISO (F, Q, problems)

% This function handles the SISO case.

Q = 1/Q;
q = floor(Q); % Q is 1/n in Malti's paper
p = Q - q;
A = squarefreq(F.num{1}, Q);
B = squarefreq(F.den{1}, Q);
status = [0 0];

% check if it is stable
if sum(abs(angle(roots(F.den{1}))) <= pi/2/Q)
    status(1) = 1;
    if strcmp(problems, 'errors')
        error('The system is not stable: the result is a nonsense.')
    elseif strcmp(problems, 'warnings')
        warning('The system is not stable: the result is a nonsense.')
    end
end
if orderpoly(B) <= orderpoly(A) + 1/Q
    status(2) = 1;
    if strcmp(problems, 'errors')
        error('According to the references (see the manual) the result should be infinite.')
    elseif strcmp(problems, 'warnings')
        warning('According to the references (see the manual) the result should be infinite.')
    end
end

if p ~= 0
    [a, s, useless] = residue(conv(A, [1 zeros(1,q)]), B);
    % a - residues; s - poles
    H2square = 0;
    for k = 1:length(s)
        if k == 1
            L = 1;
        elseif s(k) ~= s(k-1)
            L = 1;
        else % a pole with multiplicity higher than 1 was found
            L = L+1;
        end
        H2square = H2square + (-1)^(L-1) * a(k) * (-s(k))^(p-L) * combinations(p-1, L-1);
    end
    H2square = H2square * Q / sin(p*pi);
else % p == 0
    [a, s, useless] = residue(conv(A, [1 zeros(1,q-1)]), B);
    % a - residues; s - poles
    temp = sortrows([a, s], 2);
    simple = temp(1,:); % simple (and 1st appearance of repeated) poles and their residues
    repeated = []; % repeated poles (after 1st appearance) and their residues
    for k = 2:length(s)
        if temp(k,2) ~= temp(k-1,2)
            simple = [simple; temp(k,:)]; % col. 1 - residues; col. 2 - poles
        else
            repeated = [repeated; temp(k,:) 2]; % col. 1 - residues; col. 2 - poles
        end
    end
    for k = 2:size(repeated,1)
        if repeated(k,2) == repeated(k-1,2)
            repeated(k,3) = repeated(k-1,3) + 1;
        end
    end % repeated(:,3) now contains multiplicities
    s1 = simple(1,2);
    [num, den] = residue(simple(:,1), simple(:,2), 0);
    [temp1, temp2] = residue(num, den); % check if there are numerical problems
    temp = sortrows([temp1, temp2], 2);
    if norm(polysum(temp(:,2),-simple(:,2)))/abs(max(simple(:,2))) > .1 |...
            norm(polysum(temp(:,1),-simple(:,1)))/abs(max(simple(:,1))) > .1
        warning('Partial fraction expansion originated significant numerical errors.')
    end
    [a, s, useless] = residue(num, deconv(den, [1 -s1]));
    s1 = -s1; % residue gives poles with the sign changed in relation...
    s = -s; % ...to the convention used by Malti in his paper
    % s1 - chosen pole; % s - other poles; % a - residues in s
    % repeated - [residues, repeated poles, multiplicities]
    if isempty(s)
        H2square = Inf;
    else
        H2square = sum( a .* (log(s)-log(s1)) ./ (s-s1) ); % first term
    end
    if ~isempty(repeated)
        H2square = H2square + sum( repeated(:,1) .* repeated(:,2).^(1-repeated(:,3)) ./ (repeated(:,3)-1) );
    end
    H2square = H2square * Q / pi;
end
if abs(angle(sqrt(H2square))) > 1e-3 % if there imaginary part is not neglectable...
    if strcmp(problems, 'errors')
        error('A non-sensical imaginary number was obtained.')
    elseif strcmp(problems, 'warnings')
        warning('A non-sensical imaginary number was obtained.')
    end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function out = squarefreq(in, Q)

% This function receives a vector in(s) and returns out(w) = in(jw) * in'(jw).

tempreal = [];
tempimag = [];
for k = 0:length(in)-1
    temp = in(end-k) * j^(k/Q);
    tempreal = [real(temp), tempreal];
    tempimag = [imag(temp), tempimag];
end
tempreal = conv(tempreal,tempreal);
tempimag = conv(tempimag,tempimag);
out = polysum(tempreal, tempimag);