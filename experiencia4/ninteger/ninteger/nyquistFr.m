function varargout = nyquistFr(F, Q, w, delay)

% [gain, phase, w] = bodeFr(F, Q, w, delay)
% Nyquist diagram of a fractional plant. Paramter w may be a vector with the
% frequencies of the plot (in rad/s) or a cell with the limits of the
% frequency range of the plot (in rad/s). If empty a suitable range is
% provided. 
% F may be fo the form [P I lambda D mu], in which case the plant is
% P + I/(s^lambda) + D*(s^mu) and parameter Q is irrelevant; or be an lti
% object, in which case Q will be the commensurate order (the default value
% of which will be 1. For instance, plant 1/(1+s^.5) correponds to
% F = tf(1,[1 1]) and Q = 0.5.
% Parameter delay is an optional delay, the default being 0.
% A Nyquist diagram is plot if there are no return values.
% Otherwise the function returns the gain (absolute value) and the phase
% (in degrees) at frequencies w (in rad/s).
% Duarte Valério 2004% Duarte Valério 2004

if nargin < 4, delay = 0; end % there is no delay by default
if nargin < 3 | isempty(w) % no data on w was provided
    try % F is given as an ltimodel
        temp = abs([tzero(F); pole(F)]);
    catch % length(F) == 5, F is given as a list of parameters for a fractional PID
        P = F(1); I = F(2); lambda = F(3); D = F(4); mu = F(5);
        temp = sort([abs((-P+sqrt(P^2-4*D*I))/(2*D)) abs((-P-sqrt(P^2-4*D*I))/(2*D))]);
    end
    if min(temp)
        wmax = 10^ceil(log10(max(temp))) * 100;
        wmin = 10^floor(log10(min(temp))) / 100;
    else % temp is all zeros
        wmax = 100;
        wmin = .01;
    end
    w = logspace(log10(wmin), log10(wmax), 10 * ceil(log10(wmax/wmin)));
end
% there are 10 frequencies per decade
if iscell(w) % only wmax and wmin were provided
    wmin = w{1};
    wmax = w{2};
    w = logspace(log10(wmin), log10(wmax), 10 * ceil(log10(wmax/wmin)));
end
if nargin < 2 | isempty(Q), Q = 1; end % integer plants assumed as default

resp = freqrespFr(F, Q, w, delay); % freqrespFr does the important work
gain = abs(resp);
phase = rad2deg(unwrap(angle(resp)));

if nargout == 0 % there are no output variables, draw a plot
    plot(real(resp), imag(resp), 'b', real(resp), -imag(resp), 'b', -1, 0, 'r+')
    grid on
    title('Nyquist diagram')
    xlabel('Real Axis')
    ylabel('Imaginary Axis')
else
    varargout{1} = gain;
    if nargout > 1, varargout{2} = phase; end
    if nargout > 2, varargout{3} = w; end
end