function C = nid(k, v, bandwidth, n, formula, expansion, decomposition)

% function C = nid(k, v, bandwidth, n, formula, expansion, decomposition)
% This function provides integer approximations of k*s^v.
% The approximating formula is chosen by variable formula.
% The following continuous approximations are available:
% * 'crone' - first generation Crone approximation with n zeros and n
% poles, valid in frequency range [bandwidth(1); bandwidth(2)] rad/s
% * 'carlson' - Carlson approximation with at least n zeros and n poles,
% valid around frequency bandwidth rad/s or sqrt(bandwidth(1)*bandwidth(2)) rad/s
% * 'matsuda' - Matsuda approximation with n zeros and poles,
% valid in frequency range [bandwidth(1); bandwidth(2)] rad/s
% * 'cfehigh' - approximation based upon the continued fraction expansion of
% (1+s)^v with about n zeros and n poles, valid from bandwidth rad/s up
% * 'cfelow' - approximation based upon the continued fraction expansion of
% (1+1/s)^(-v) with about n zeros and n poles, valid until bandwidth rad/s
% The following digital approximations are available:
% * 'tustin' - Tustin approximation
% * 'simpson' - Simpson approximation
% * '1ofd' - first order backwards finite difference approximation
% * '2ofd' - second order backwards finite difference approximation
% * '3ofd' - third order backwards finite difference approximation
% * 'delta' - delta transform approximation
% * 'impulse' - impulse response approximation
% * 'step' - step response approximation
% In all these cases the approximation has up to n delays, and variable
% expansion (which may be ommited and is neglected for continous
% approximations) may be one of the following:
% 'mcltime' (default), 'mcltimeINV', 'cfe', 'cfeINV'
% For all digital approximations, bandwidth is the sampling time in seconds.
% Variable decomposition may be ommited and its values may be:
% * 'frac' - (default) order v - floor(v) is approximated and added to the
% integer part floor(v)
% * 'all' - order v is approximated; this is not recommended
% Duarte Valério 2004

if nargin < 7 % defaults are set
    decomposition = 'frac';
end
if nargin < 6
    expansion = 'mcltime';
end
if isempty(expansion)
    expansion = 'mcltime';
end
if strcmp(formula, 'crone') | strcmp(formula, 'matsuda')
    if length(bandwidth) < 2
        error('Variable bandwidth should consist of two frequencies.')
    end
    wl = bandwidth(1);
    wh = bandwidth(2);
elseif strcmp(formula, 'carlson') & ~strcmp(decomposition, 'frac') & abs(v) > 1
    error('Carlson method with |v|>1 demands that decomposition be ''frac''.')
elseif strcmp(formula, 'cfehigh')
    bandwidth = bandwidth(1);
elseif strcmp(formula, 'cfelow')
    bandwidth = bandwidth(end);
else % all digital approximations
    Ts = bandwidth(1); % this is a sampling time, NOT a frequency
end

if strcmp(decomposition, 'frac') % only the fractional part is expanded
    C = nid(k, v-floor(v), bandwidth, n, formula, expansion, 'all');
    switch formula
        case {'crone', 'matsuda', 'carlson', 'cfehigh', 'cfelow'}
        % continuous cases
            C = C * (tf('s'))^(floor(v));
        case '1ofd'
            C = C * (tf([1 -1],Ts,Ts,'Variable','z^-1'))^(floor(v));
        case '2ofd'
            C = C * (tf([3 -4 1],2*Ts,Ts,'Variable','z^-1'))^(floor(v));
        case '3ofd'
            C = C * (tf([11 -18 9 -2],6*Ts,Ts,'Variable','z^-1'))^(floor(v));
        case {'tustin', 'delta', 'impulse', 'step'}
            C = C * (tf(2*[1 -1],Ts*[1 1],Ts,'Variable','z^-1'))^(floor(v));
        case 'simpson'
            C = C * (tf(3*[1 0 -1],Ts*[1 4 1],Ts,'Variable','z^-1'))^(floor(v));
    end
elseif strcmp(decomposition, 'all') % everything is expanded
    switch formula
        case 'crone'
            C = crone1(k, v, wl, wh, n);
        case 'carlson'
            C = newton(k, v, bandwidth, n, tf('s'), 'zp');
        case 'matsuda'
            C = matsuda(k, v, wl, wh, n);
        case 'cfehigh'
            C = cfehigh(k, v, bandwidth, n);
        case 'cfelow'
            C = cfelow(k, v, bandwidth, n);
        otherwise % digital approximations or errors
            C = digital(k, v, Ts, n, formula, expansion);
    end
else
    error('The decomposition has an invalid format.')
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% function C = crone1(k, v, wl, wh, n)
% 
% % function C = crone1(k, v, wl, wh, n)
% % This function returns a first generation CRONE controller,
% % that is to say, a frequency domain approximation of a controller
% % with the transfer function k*s^v.
% % The approximation is valid in [wl; wh] rad/s and has n zeros and n poles.
% % Duarte Valério 2003
% 
% alphaXeta = (wh / wl) ^ (1/n);
% alpha = alphaXeta ^ abs(v);
% eta = alphaXeta / alpha;
% if v>0
%    zeros = wl * sqrt(eta);
%    poles = zeros * alpha;
%    for i = 2:n
%       zeros = [zeros poles(end)*eta];
%       poles = [poles zeros(end)*alpha];
%    end
% else
%    poles = wl * sqrt(eta);
%    zeros = poles * alpha;
%    for i = 2:n
%       poles = [poles zeros(end)*eta];
%       zeros = [zeros poles(end)*alpha];
%    end
% end
% C = tf(zpk(-zeros, -poles, 1));
% C = k * C / bode(C, 1);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function C = matsuda(k, v, wl, wh, n)

% function C = matsuda(k, v, wl, wh, n)
% This function returns a frequency domain approximation of a controller
% with the transfer function k*s^v, using Matsuda method
% as seen in function matsudaCFE.
% The approximation is valid in [wl; wh] rad/s.
% n is the number of zeros PLUS the number of poles.
% If it is odd, the number of zeros is 1 more than the one of poles.
% Duarte Valério 2004

% function to interpolate
w = logspace(log10(wl), log10(wh), n+1);
gain = 20 * log10(abs(w.^v));
% function matsudaCFE handles the rest
C = k * matsudaCFE(w, gain);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function C = cfehigh(k, v, bandwidth, n)

% function C = cfehigh(k, v, bandwidth, n)
% This function returns a frequency domain approximation of a controller
% with the transfer function k*s^v, approximated by
% k*bandwidth^v times a continued fraction expansion of
% (1+s/bandwidth/s)^v
% Duarte Valério 2005

q = tf('s')/bandwidth;
a = [0 ones(1, 2*n)];
b = [ 0 1 -v*q ];
for i = 1 : n
    b = [ b , i*(i+v)*q/(2*i*(2*i-1)) , i*(i-v)*q/(2*i*(2*i+1)) ];
end
C = k * bandwidth^v * contfraceval(a, b, 2*n);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function C = cfelow(k, v, bandwidth, n)

% function C = cfelow(k, v, bandwidth, n)
% This function returns a frequency domain approximation of a controller
% with the transfer function k*s^v, approximated by
% k*bandwidth^v times a continued fraction expansion of
% (1+bandwidth/s)^(-v)
% Duarte Valério 2005

q = tf('s')/bandwidth;
a = [0 ones(1, 2*n)];
b = [ 0 1 v/q ];
for i = 1 : n
    b = [ b , i*(i-v)/(q*2*i*(2*i-1)) , i*(i+v)/(q*2*i*(2*i+1)) ];
end
C = k * bandwidth^v * tf(ss(contfraceval(a, b, 2*n)));
% this is bacuse s, showing up in the numerator,
% makes unnecessarily high powers to appear in the final result

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function C = digital(k, v, Ts, n, formula, expansion)

% function C = digital(k, v, Ts, n, formula, expansion)
% This function returns a discrete time domain approximation of a controller
% with the transfer function k*s^v, using one out of thirty-two methods.
% The sampling time is Ts seconds. The approximation has up to n delays.
% Variable method may be one of the following:
% 'tustin', 'simpson', '1ofd', '2ofd', '3ofd', 'delta', 'impulse' or 'step'.
% Variable expansion may be one of the following:
% 'mcltime', 'mcltimeINV', 'cfe' or 'cfeINV'.
% Duarte Valério 2004

switch expansion
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
case 'mcltime'
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    switch formula
        
    case '1ofd'
        % matched poles and zeros (or finite differences, or Gr¨unwald-Letnikoff) formula
        dc = [];
        if isinteger(v) & v < 0
            for i = 0:n
                dc(i+1) = gamma(i-v) / (gamma(-v) * gamma(i+1));
            end
        else
            for i = 0:n
                dc(i+1) = (-1)^i * gamma(v+1) / (gamma(i+1) * gamma(v-i+1));
            end
        end
        dc = dc * (1/Ts)^v;
        
    case '2ofd'
        % second order finite differences formula
        dc = zeros(1,n+1);
        for i = 0:n
            for j = 0:i
                dc(i+1) = dc(i+1) + (-1)^i / (gamma(v-j+1) * 3^j *...
                    gamma(j+1) * gamma(i-j+1) * gamma(v-i+j+1));
            end
        end
        dc = dc * 3^v * (gamma(v+1))^2 / (2 * Ts)^v;
        
    case '3ofd'
        % third order finite differences formula
        dc = zeros(1,n+1);
        i = sqrt(-1);
        for r = 0:n
            for q = 0:r
                for p = 0:q
                    dc(r+1) = dc(r+1) + (-1)^p *...
                        (-7/4-i*sqrt(39)/4)^(v-q+p) *...
                        (-7/4+i*sqrt(39)/4)^(v-r+q) /...
                        (gamma(p+1) * gamma(v-p+1) * gamma(q-p+1) *...
                        gamma(v-q+p+1) * gamma(r-q+1) * gamma(v-r+q+1));
                end
            end
        end
        dc = real(dc) * 2^v * (gamma(v+1))^3 / (6*Ts)^v;
        % the imaginary part ought to be 0, but isn't due to round-off errors
        
    case 'tustin'
        % Tustin formula
        dc = zeros(1,n+1);
        for i = 0:n
            for j = 0:i
                dc(i+1) = dc(i+1) + (-1)^j * gamma(v+1) * gamma(-v+1) /...
                    (gamma(v-j+1) * gamma(j+1) * gamma(i-j+1) * gamma(-v+j-i+1));
            end
        end
        dc = dc * (2/Ts)^v;
        
    case 'simpson'
        % Simpson formula
        dc = zeros(1,n+1);
        for j = 0:n
            for m = 0:floor(j/2)
                for i = 2*m:j
                    dc(j+1) = dc(j+1) + (-1)^m * (2-sqrt(3))^(-v-i+2*m) *...
                        (2+sqrt(3))^(-v-j+i) / (gamma(m+1) * gamma(v-m+1) *...
                        gamma(i-2*m+1) * gamma(-v-i+2*m+1) * gamma(j-i+1) *...
                        gamma(-v-j+i+1));
                end
            end
        end
        dc = dc * gamma(v+1) * (gamma(-v+1))^2 * (3/Ts)^v;
        
    case 'delta'
        % delta formula
        v = -v; % cancelled at the end when coefficients order is inverted
        % auxiliary matrix F
        F = [ones(n,1) zeros(n,n-1)];
        for j = 2:n
            for i = j:n
                F(i,j) = F(i-1,j) + (i-1) * F(i-1,j-1);
            end
        end
        % delta formula -- coefficients in powers of (gamma*T - 1)
        dc = [(log(2))^v zeros(1,n)];
        for i = 1:n
            for j = 1:i
                dc(i+1) = dc(i+1) + (-1)^(j+1) * (log(2))^(v-i+j-1) * F(i,j) * gamma(v+1) /...
                    (gamma(v-i+j) * gamma(i+1) * 2^i);
            end
        end
        dc = dc * (1/Ts)^v;
        % turned into a causal z^-1 TF...
        temp = tf(0,'Variable','z');
        for i = 1:n+1
            temp = temp + tf([1 -2],1,Ts,'Variable','z')^(i-1) * dc(i);
        end
        dc = temp.num{1}(n+1:-1:1) / Ts; % inverting the order of the coefficients cancels the -v above
        
    case 'impulse'
        % exact impulse response formula
        dc = (Ts*(1:n)) .^ (-v-1) / gamma(-v);
        dc = [Ts^(-v)/gamma(-v+1)-Ts^(-v-1)/gamma(-v), dc];
        
    case 'step'
        % exact step response formula
        dc = Ts^(-v)/gamma(-v+1)-Ts^(-v-1)/gamma(-v);
        for i = 1:n
            dc = [dc, (i*Ts) .^ (-v) / gamma(-v+1) - sum(dc)];
        end
        
    otherwise
        error ('The formula has an invalid format.');
    end
    
    % a tf object is built from vector of coefficients dc
    C = tf(k*dc, 1, Ts, 'Variable', 'z^-1');
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
case 'cfe'
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    switch formula
        
    case '1ofd'
        % first-order backward finite difference formula
        a = [0 ones(1, n+1)];
        b = [0 1 tf([0, v], 1, -1, 'Variable', 'z^-1')];
        for i = 3:n+1
            b = [b, tf([0, -ceil((i-2)/2) * (ceil((i-2)/2) - (-1)^i * v) / ((i-1) * (i-2))], 1, -1,...
                    'Variable','z^-1')];
        end
        dc = contfraceval (a, b, n+1);
        dc.Ts = Ts;
        C = k * dc / Ts^v;
        
    case 'tustin'
        % Tustin formula
        a = [1 tf([-1, -v], [0, 1], -1, 'Variable', 'z^-1')];
        b = [0 tf(2*v)];
        for i = 1:ceil(n/2)
            a = [a, tf(2*i+1, [0, -1], -1, 'Variable', 'z^-1')];
            b = [b, v^2-i^2];
        end
        dc = contfraceval (a, b, ceil(n/2));
        dc.Ts = Ts;
        C = k * (2/Ts)^v * dc;
        
    case {'simpson', '2ofd', '3ofd', 'delta', 'impulse', 'step'}
        % Simpson formula
        % second order finite differences formula
        % third order finite differences formula
        % delta formula
        temp = digital (k, v, Ts, n+2, formula,'mcltime');
        c = temp.num{1};
        c = [1, zeros(1,length(c)-1); c];
        [a, temp] = contfracf (c, n+1);
        b = [temp(1), tf(temp(2))];
        for i = 3:n+2
            b = [b tf([0 temp(i)], 1, -1, 'Variable', 'z^-1')];
        end
        C = contfraceval (a, b, n+1);
        C.Ts = Ts;
        
    otherwise
        error ('The formula has an invalid format.');
    end
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
case 'mcltimeINV'
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    temp = digital(1, -v, Ts, n, formula, 'mcltime');
    C = k * tf(temp.den{1}, temp.num{1}, Ts, 'Variable', 'z^-1');
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
case 'cfeINV'
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    temp = digital(1, -v, Ts, n, formula, 'cfe');
    C = k * tf(temp.den{1}, temp.num{1}, Ts, 'Variable', 'z^-1');
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
otherwise
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    error ('The expansion has an invalid format.');
end

% last of all, the transfer function is normalised so that
% the independent coefficient of the denominator is 1
norm = C.den{1}(1);
C.num{1} = C.num{1}/norm;
C.den{1} = C.den{1}/norm;