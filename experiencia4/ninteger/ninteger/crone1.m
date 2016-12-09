function C = crone1(k, v, wl, wh, n)

% C = crone1(k, v, wl, wh, n)
% This function provides integer, first generation Crone
% approximations of k*s^v, valid in the [wl; wh] rad/s frequency range.
% If v is real, n(1) is the number of zeros and poles of the approximation.
% If v is complex, n(1) is the number of poles and n(end) the number
% of zeros of the approximation.
% Duarte Valério 2005

if ~isreal(v) & n(1)==n(end)
    error('Complex differentiation orders require a different number of zeros and poles.')
end
if isreal(v)
    n = n(1); % the number of zeros and poles need not be different
    alphaXeta = (wh / wl) ^ (1/n);
    alpha = alphaXeta ^ abs(v);
    eta = alphaXeta / alpha;
    if v>0
        zeros = wl * sqrt(eta);
        poles = zeros * alpha;
        for i = 2:n
            zeros = [zeros poles(end)*eta];
            poles = [poles zeros(end)*alpha];
        end
    else
        poles = wl * sqrt(eta);
        zeros = poles * alpha;
        for i = 2:n
            poles = [poles zeros(end)*eta];
            zeros = [zeros poles(end)*alpha];
        end
    end
    C = tf(zpk(-zeros, -poles, 1));
    C = k * C / bode(C, 1);
else % v is complex
    m = n(end); % number of zeros
    n = n(1); % number of poles
    a = real(v); b = imag(v); % v = a + jb
    alpha = (wh/wl) ^ (a*(n+m)/(n*m));
    eta = 10 ^ ((pi*log10(alpha)) / (pi+2*log10(alpha)*log(10)*b*tanh(-b*pi/2)));
    zeros = wl*sqrt(eta);
    for i = 2:m
        % while zeros(end) < wh
        zeros = [zeros zeros(end)*eta];
    end
    poles = wl*sqrt(alpha);
    for i = 2:n
        % while poles(end) < wh
        poles = [poles poles(end)*alpha];
    end
    C = tf(zpk(-zeros, -poles, 1));
    C = k * C / bode(C, 1);
end