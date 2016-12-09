function resp = freqrespFr(F, Q, w, delay)

% resp = freqrespFr(F, Q, w, delay)
% This function finds the frequency response of a fractional plant at
% frequencies in vector w. The response is given as a vector of complex
% numbers.
% F may be fo the form [P I lambda D mu], in which case the plant is
% P + I/(s^lambda) + D*(s^mu) and parameter Q is irrelevant; or be an lti
% object, in which case Q will be the commensurate order (the default value
% of which will be 1. For instance, plant 1/(1+s^.5) correponds to
% F = tf(1,[1 1]) and Q = 0.5.
% Duarte Valério 2004

if nargin < 4, delay = 0; end % there is no delay by default
if isempty(Q), Q = 1; end % integer plants assumed as default

if length(F) ~= 5 % F is given as an ltimodel
    F = tf(F);
    num = F.num{1};
    den = F.den{1};
    tempNum = 0;
    tempDen = 0;
    for k = 1:length(num)
        tempNum = tempNum + num(end-k+1) * (j*w).^(k*Q);
    end
    for k = 1:length(den)
        tempDen = tempDen + den(end-k+1) * (j*w).^(k*Q);
    end
    resp = tempNum ./ tempDen; % frequency response without delay
else % length(F) == 5, F is given as a list of parameters for a fractional PID
    P = F(1); I = F(2); lambda = F(3); D = F(4); mu = F(5);
    resp = P + (I ./ ((j*w) .^ lambda)) + (D * (j*w).^mu); % frequency response without delay
end
resp = resp .* exp(-j*w*delay); % the effect of the delay is added