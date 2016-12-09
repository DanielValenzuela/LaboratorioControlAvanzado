function [G, J, handle] = lawro (w, gain, phase, Q, n, m, H, coefficients)

% [G, J, handle] = lawro (w, gain, phase, Q, n, m, H, coefficients)
% This function returns a model for a plant
% with a known frequency behaviour.
% The model is
% b(1)*s^(m*Q) + b(2)*s^((m-1)Q) + ... + b(end-2)*s^(2*Q) + b(end-1)*s^Q + b(end)
% -------------------------------------------------------------------------------
% a(1)*s^(n*Q) + a(2)*s^((n-1)Q) + ... + a(end-2)*s^(2*Q) + a(end-1)*s^Q + a(end)
% The function receives the gain in dB and the phase in degrees
% for frequencies, in rad/s, specified in w.
% Parameters Q, n and m must be supplied.
% H may not be supplied and is an initial estimate for the matrix of the
% Levy identification method; k*(m+n+1) is a good starting point if nothing
% is known, k being some real number larger than 1.
% Parameter coefficients is also optional and is an initial estimate of the
% coefficients of G, given as [b(1) ... b(end) a(1) ... a(end-1)]', a(end) being 1.
% A structure is returned with fields num and den,
% containing vectors b and a respectively.
% J is the quadratic error per sampling frequency.
% If the last output argument exists, a handle for a Bode plot will be returned.
% Duarte Valério 2003

if nargin < 8 | isempty(coefficients), coefficients = zeros(n+m+1, 1); end
if nargin < 7 | isempty(H), H = eye(n+m+1); end % Z needs no initial estimate

if size(w, 1) < size(w, 2)
    w = w'; % now w is a column vector for sure
end
if size(gain, 1) < size(gain, 2)
    gain = gain'; % now w is a column vector for sure
end
if size(phase, 1) < size(phase, 2)
    phase = phase'; % now w is a column vector for sure
end

X = 10.^(gain/20) .* exp(j * deg2rad(phase)); % frequency behaviour of the plant

for k = 1:length(w)
    ww = w(k); XX = X(k); % frequency behaviour of the plant at the frequency under concern
    s = []; for l = 1:n, s = [s; (j*ww)^(l*Q)]; end
    t = []; for l = 0:m, t = [t; (j*ww)^(l*Q)]; end
    u = [t; -XX*s];
    Z = H * ( eye(size(H)) - real(u)*real(transpose(u))*H / (1/2 + real(transpose(u))*H*real(u)) );
    H = Z * ( eye(size(H)) - imag(u)*imag(transpose(u))*H / (1/2 + imag(transpose(u))*Z*imag(u)) );
    coefficients = coefficients + H * ( u*(conj(XX)-u'*coefficients) + conj(u)*(XX-transpose(u)*coefficients) );
end

G.num = coefficients(m+1:-1:1);
G.den = [coefficients(end:-1:m+2); 1];

% index J
if nargout > 1
    tempNum = 0;
    for c = 1:length(G.num)
        tempNum = tempNum + G.num(c) * (j*w).^((m-c+1)*Q);
    end
    tempDen = 0;
    for c = 1:length(G.den)
        tempDen = tempDen + G.den(c) * (j*w).^((n-c+1)*Q);
    end
    J = sum((abs(10.^(gain/20).*exp(j*deg2rad(phase)) - tempNum./tempDen)).^2) / length(w);
end

% Bode plots
if nargout == 3
    wNew = logspace(floor(log10(w(1))), ceil(log10(w(end))), max(50, length(w)));
    tempNum = 0;
    for c = 1:length(G.num)
        tempNum = tempNum + G.num(c) * (j*wNew).^((m-c+1)*Q);
    end
    tempDen = 0;
    for c = 1:length(G.den)
        tempDen = tempDen + G.den(c) * (j*wNew).^((n-c+1)*Q);
    end
    gainNew = 20 * log10(abs(tempNum ./ tempDen));
    phaseNew = rad2deg(angle(tempNum ./ tempDen));
    handle = figure;
    subplot(2,1,1)
    semilogx(w,gain,'.', wNew,gainNew)
    subplot(2,1,2)
    semilogx(w,phase,'.', wNew,phaseNew)
end