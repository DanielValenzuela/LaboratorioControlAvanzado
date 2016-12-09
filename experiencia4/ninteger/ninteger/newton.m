function C = newton (k, v, bandwidth, n, g, stop)

% function C = newton (k, v, bandwidth, n, g, stop)
% Returns an approximation C = k*g^v, where g is a transfer function,
% valid in the frequency range [bandwidth(1); bandwidth(2)] rad/s or
% around bandwidth rad/s if bandwidth has only one element.
% The approximation is reckoned by a Newton process with n iterations
% (if stop is 'iter' or is ommited) or with a number of iterations
% leading to at least n zeros and n poles (if stop is 'zp').
% Duarte Valério 2004

if nargin < 6 % n is a number of iterations by default
    stop = 'iter';
end
if length(bandwidth) < 2
    wc = bandwidth;
else
    wc = sqrt(bandwidth(1) * bandwidth(2));
end
if abs(v) > 1
    m = floor(v); % integer part of v
else
    m = 0;
end
a = round(1 / (v-m)); % fractional part of v, rounded to the inverse of an integer
if abs(a) < 2
    a = sign(a) * 2; % 1 and -1 won't do; use 2 and -2 instead
end
if (v-m) ~= (1/a) % if the order was rounded, warn the user
    if sign(a) > 0
        warning(['Order v was rounded to ' num2str(m) ' + 1 / ' num2str(a)])
    else
        warning(['Order v was rounded to ' num2str(m) ' - 1 / ' num2str(-a)])
    end
end
C = tf(1);
if strcmp(stop, 'zp') % stop after getting some zeros and poles
    while min(length(C.num{1}), length(C.den{1})) < n+1
        tempNum = (a-1) * C^a + (a+1) * g;
        tempDen = (a+1) * C^a + (a-1) * g;
        C = C * tempNum / tempDen;
    end
else
    for i = 1:n % stop after some iterations
        tempNum = (a-1) * C^a + (a+1) * g;
        tempDen = (a+1) * C^a + (a-1) * g;
        C = C * tempNum / tempDen;
    end
end
C = tf(ss(C)); % this eliminates repeated zeros and poles
[zeros, poles, gain] = zpkdata(C, 'v');
C = tf(zpk(zeros*wc*bode(g,1), poles*wc*bode(g,1), gain)); % this recentres the frequency range
C = tf('s')^m * k * C * bode(g,1)^v / bode(C,1);