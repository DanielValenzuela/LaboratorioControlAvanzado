function Hinf = normhinfFr (F, Q, w)

% function Hinf = normhinfFr (F, Q, w)
% The Hinf norm of transfer function F, commensurate of order Q, is found
% using sigmaFr. w (in rad/s) is either a list of frequencies
% or a cell-array with the frequency range of interest, {wMin wMax}.
% Q is optional (default is 1) and w too (if given, it should be chosen
% with care; this may be useful to speed calculations up by using fewer values,
% but under pain of obtaining inaccurate results).
% Duarte Valério 2004

if nargin < 2, Q = 1; end % integer plants assumed as default
if nargin < 3 % bounds for w will be found; sigmaFr will use 10 frequencies/decade
    temp = abs([tzero(F); pole(F)]);
    if min(temp)
        wmax = 10^ceil(log10(max(temp))) * 1e5;
        wmin = 10^floor(log10(min(temp))) / 1e5;
    else % temp has zeros
        wmax = 1e5;
        wmin = 1e-5;
    end
    singval = sigmaFr(F, Q, {wmin wmax});
else % user-provided w
    singval = sigmaFr(F, Q, w);
end
Hinf = max(max(singval));