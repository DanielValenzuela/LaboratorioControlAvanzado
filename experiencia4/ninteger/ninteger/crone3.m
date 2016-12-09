function [a, b, w0, w, gainC, phaseC, C] = crone3(G,...
    vargain, varzeros, varpoles, wl, wh, spec, st, n)

% [a, b, w0, w, gainC, phaseC] = crone3(G,...
%     vargain, varzeros, varpoles, wl, wh, spec, st)
% This function the parameters for a controller that ensures an open-loop
% dynamic given by the transfer function (s/w0)^(a+jb) for plant G,
% that must be a tf object.
% Vector vargain contains the most negative and positive variations
% that the gain of G may undergo.
% Matrix varzeros has two columns and as many lines as the zeros of G;
% each line has, in its two positions, the most negative variation
% and the most positive variations (in rad/s) that the corresponding
% zero may undergo.
% Information on zeros must be ordered according to their increasing order.
% Matrix varpoles is similar to matrix varzeros,
% containing information on variations poles may undergo.
% The open-loop will have a Nichols diagram
% linear in the [wl; wh] rad/s range and tangent to the curve
% corresponding to spec dB of resonance gain in closed-loop or to a damping
% coefficient of spec (without dimensions) in closed-loop.
% Variable st allows choosing which:
% 'g' - resonance gain
% 'd' - damping coefficient
% If ommited, the resonance gain will be used by default.
% Beyond the specification of the closed-loop dynamic, the function returns
% the Bode diagram the controller must have: at frequencies w rad/s, the
% gain must be bodeGain dB and the phase must be bodePhase degrees.
% If called with sintax
% [a, b, w0, w, gainC, phaseC, C] = crone3(S,...
%     vargain, varzeros, varpoles, w1, wl, wh, spec, st, n)
% an approximation C of the controller with n poles and zeros will be
% obtained with function crone2 or with function crone2Z (depending on
% wether S is time-sampled or not), but this option is not advisable since
% frequencies in w are too many for a good result to be likely.
% Check the manual for further informations.
% Duarte Valério 2003

% specification is checked
if nargin < 8
   st = 'g';
elseif (st ~= 'd') & (st ~= 'g')
    error ('The performance specification has an invalid format.');
end
if st == 'g'
    spec = 10^(spec/20); % conversion from dB to absolute value
end

% poles, zeros and gain are found
[zeros, poles, gain] = zpkdata(G, 'v');
poles = sort(poles);
zeros = sort(zeros);
Ts = G.Ts;
variable = G.Variable;

% the desired optimum is found
w = logspace(log10(wl), log10(wh));
[yslope, value] = fminsearch(@crone3Aux1, 1, [], gain, zeros, poles,...
    Ts, variable, vargain, varzeros, varpoles, w, spec, st); % dB/rad
[yslopeNew, valueNew] = fminsearch(@crone3Aux1, -1, [], gain, zeros, poles,...
    Ts, variable, vargain, varzeros, varpoles, w, spec, st); % dB/rad
if valueNew < value
    yslope = yslopeNew
end

% parameters wanted are found: vertical adjustment...
x = fminsearch(@crone3Aux2, -pi, [], yslope, spec, st);
if st=='g'
    if (spec>1 & yslope>0) | spec<1
        y = 20*log10((-cos(x)-sqrt((cos(x))^2-(1-1/(spec^2)))) / (1-1/(spec^2)));
    elseif spec>1
        y = 20*log10((-cos(x)+sqrt((cos(x))^2-(1-1/(spec^2)))) / (1-1/(spec^2)));
    else % if spec==1
        y = 20*log10(-1/(2*cos(x)) * (cos(x)<0));
    end
else
    temp = cos(x)-1-cos(pi^2/(2*acos(-spec)));
    if yslope>0
        y = 20*log10(-temp-sqrt(temp^2-1));
    else % if yslope<0
        y = 20*log10(-temp+sqrt(temp^2-1));
    end
end

% ...order adjustment...
A = 100 * yslope / log(10);
if yslope<0
    B = 10*y - 10*x*yslope + A + yslope*log(10);
else
    B = 10*y - 10*x*yslope + A - yslope*log(10);
end
C = 20*y - 20*x*yslope;
solution = [(-B + sqrt(B^2-4*A*C)) / (2*A), (-B - sqrt(B^2-4*A*C)) / (2*A)];
if isreal(solution(1))
    b0 = sign(yslope) * 2 * sqrt(solution(1)) / pi;
    a0 = (y - x*yslope + 10*yslope*solution(1)/log(10)) / (pi/2);
else
    b0 = sign(yslope) * 2 * sqrt(solution(2)) / pi;
    a0 = (y - x*yslope + 10*yslope*solution(2)/log(10)) / (pi/2);
end
ab = fminsearch(@crone3Aux3, [a0 b0], [], yslope, x, y);
a = ab(1);
b = ab(2);

% ...and Bode diagram
w = w';
gain = 20 * a * log10(w) + 20 * log10(cosh(b*pi/2)); % dB
phase = sign(b) * b * log(10) * tanh(b*pi/2) * log10(w) + a*pi/2; % rad

% phase correction
if mean(phase) < 0
    phase = rad2deg(phase) +...
        360 * floor(abs(mean(phase)) / (2*pi)); % degrees, from -360 to 0
else
    phase = rad2deg(phase) - 360 -...
        360 * floor(abs(mean(phase)) / (2*pi)); % degrees, from -360 to 0
end

% gain correction
wf_0log = -a*(pi/2) / (sign(b)*b*log(10)*tanh(b*pi/2));
wf_360log = (2*pi - a*(pi/2)) / (sign(b)*b*log(10)*tanh(b*pi/2));
tempW = logspace(wf_0log, wf_360log);
tempGain = 20 * a * log10(tempW) + 20 * log10(cosh(b*pi/2)); % dB
tempPhase = sign(b) * b * log(10) * tanh(b*pi/2) * log10(tempW) + a*pi/2; % rad
if mean(tempPhase) < 0
    tempPhase = tempPhase +...
        2*pi * floor(abs(mean(tempPhase)) / (2*pi)); % rad, from -2*pi to 0
else
    tempPhase = tempPhase - 2*pi -...
        2*pi * floor(abs(mean(tempPhase)) / (2*pi)); % rad, from -2*pi to 0
end
if st=='g'
    while max(20 * log10(10.^(tempGain / 20) ./ sqrt(1+(10.^(tempGain / 20)).^2+...
            2*10.^(tempGain / 20).*cos(tempPhase)))) > spec
        tempGain = tempGain - 2*pi * abs(yslope);
        gain = gain - 2*pi * abs(yslope);
    end
else
%     while min(-cos(pi^2 ./ (2 * acos(((10.^(tempGain / 20)).^2 +...
%             2*(10.^(tempGain / 20)).*(cos(phase')-1) + 1) ./...
%             (2*(10.^(tempGain / 20))))))) < spec
%         tempGain = tempGain - 2*pi * abs(yslope);
%         gain = gain - 2*pi * abs(yslope);
%     end
end

% the Bode diagram of the controller is obtained
[gainG, phaseG] = bode(G, w);
gainG = 20 * log10(squeeze(gainG)); % dB
phaseG = squeeze(phaseG); % degrees
gainC = gain - gainG; % dB
phaseC = phase - phaseG; % degrees

% w0 is obtained by interpolation in gain(w)
w0 = 10^(log10(w(end)) + (20*log10(cosh(b*pi/2)) - gain(end)) *...
    (log10(w(end))-log10(w(1))) / (gain(end)-gain(1))); % rad/s

% an approximation of the controller is obtained if wanted
if nargin==10 & nargout==7
    if Ts == 0
        C = crone2(w, bodeGain, bodePhase, n);
    else
        C = crone2z(w, bodeGain, bodePhase, n, Ts);
    end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function error = crone3Aux1(yslope, gain, zeros, poles, Ts, variable,...
    vargain, varzeros, varpoles, w, spec, st)

% error = crone3Aux1(yslope, gain, zeros, poles, Ts, variable,...
%     vargain, varzeros, varpoles, w1, w, spec, st)
% This function reckons the error in fulfilling a performance specification
% when a Nichols diagram has a certain slope.
% Parameters are yslope, the Nichols diagram slope in dB/rad;
% gain, zeros and poles, the zpkdata of the plant to control;
% Ts and variable, the Ts and Variable fields of the plant to control;
% vargain, varzeros and varpoles, as explained in crone3;
% w1, as explained in crone3; a set of frequencies, w rad/s, for evaluating
% the frequency response; and variables spec and st, as explained in
% crone3.
% Check the manual for further informations.
% Duarte Valério 2003

% vertical adjustment
x = fminsearch(@crone3Aux2, -pi, [], yslope, spec, st);
if st=='g'
    if (spec>1 & yslope>0) | spec<1
        y = 20*log10((-cos(x)-sqrt((cos(x))^2-(1-1/(spec^2)))) / (1-1/(spec^2)));
    elseif spec>1
        y = 20*log10((-cos(x)+sqrt((cos(x))^2-(1-1/(sepc^2)))) / (1-1/(spec^2)));
    else % if spec==1
        y = 20*log10(-1/(2*cos(x)) * (cos(x)<0));
    end
else
    temp = cos(x)-1-cos(pi^2/(2*acos(-spec)));
    if yslope>0
        y = 20*log10(-temp-sqrt(temp^2-1));
    else % if yslope<0
        y = 20*log10(-temp+sqrt(temp^2-1));
    end
end

% order adjustment
A = 100 * yslope / log(10);
if yslope<0
    B = 10*y - 10*x*yslope + A + yslope*log(10);
else
    B = 10*y - 10*x*yslope + A - yslope*log(10);
end
C = 20*y - 20*x*yslope;
solution = [(-B + sqrt(B^2-4*A*C)) / (2*A), (-B - sqrt(B^2-4*A*C)) / (2*A)];
if isreal(solution(1))
    b0 = sign(yslope) * 2 * sqrt(solution(1)) / pi;
    a0 = (y - x*yslope + 10*yslope*solution(1)/log(10)) / (pi/2);
else
    b0 = sign(yslope) * 2 * sqrt(solution(2)) / pi;
    a0 = (y - x*yslope + 10*yslope*solution(2)/log(10)) / (pi/2);
end
ab = fminsearch(@crone3Aux3, [a0 b0], [], yslope, x, y);
a = ab(1);
b = ab(2);
if ~isreal(a) | ~isreal(b)
    error = Inf;
    return
end
    
% Bode diagram
bodeGain = 20 * a * log10(w) + 20 * log10(cosh(b*pi/2)); % dB
bodeGain = 10.^(bodeGain / 20);
bodePhase = sign(b) * b * log(10) * tanh(b*pi/2) * log10(w) + a*pi/2; % rad

% phase correction
if mean(bodePhase) < 0
    bodePhase = rad2deg(bodePhase) +...
        360 * floor(abs(mean(bodePhase)) / (2*pi)); % degrees, from -360 to 0
else
    bodePhase = rad2deg(bodePhase) - 360 -...
        360 * floor(abs(mean(bodePhase)) / (2*pi)); % degrees, from -360 to 0
end

% gain correction
wf_0log = -a*(pi/2) / (sign(b)*b*log(10)*tanh(b*pi/2));
wf_360log = (2*pi - a*(pi/2)) / (sign(b)*b*log(10)*tanh(b*pi/2));
tempW = logspace(wf_0log, wf_360log);
tempGain = 20 * a * log10(tempW) + 20 * log10(cosh(b*pi/2)); % dB
tempPhase = sign(b) * b * log(10) * tanh(b*pi/2) * log10(tempW) + a*pi/2; % rad
if mean(tempPhase) < 0
    tempPhase = rad2deg(tempPhase) +...
        360 * floor(abs(mean(tempPhase)) / (2*pi)); % degrees, from -360 to 360
else
    tempPhase = rad2deg(tempPhase) - 360 -...
        360 * floor(abs(mean(tempPhase)) / (2*pi)); % degrees, from -360 to 360
end
if st=='g'
    while reckoning(10.^(tempGain/20), deg2rad(tempPhase), st) > spec
        tempGain = tempGain - 2*pi * abs(yslope);
        bodeGain = bodeGain - 2*pi * abs(yslope);
    end
else
    while reckoning(10.^(tempGain/20), deg2rad(tempPhase), st) < spec
        tempGain = tempGain - 2*pi * abs(yslope);
        bodeGain = bodeGain - 2*pi * abs(yslope);
    end
end

% the penalty function: gain variations...
bodeGainNew = bodeGain * abs(gain + vargain(1));
delta = spec - reckoning(bodeGainNew, bodePhase*sign(gain+vargain(1)), st);
bodeGainNew = bodeGain * abs(gain + vargain(2));
delta = [delta;...
        spec - reckoning(bodeGainNew, bodePhase*sign(gain+vargain(2)), st)];
    
% ...zero variations...
for i=1:size(varzeros,1)
    if imag(zeros(i)) > 0 % this is a complex zero that was already cared for
        continue % skip this zero
    end
    for j=1:2
        if imag(zeros(i))==0
            correction = zpk(zeros(i)+varzeros(i,j), zeros(i), 1,...
                Ts, 'Variable', variable);
        else
            correction = zpk([zeros(i)+varzeros(i,j)...
                conj(zeros(i))+conj(varzeros(i,j))],...
                [zeros(i) conj(zeros(i))], 1, Ts, 'Variable', variable);
        end
        [bodeGainNew, bodePhaseNew] = bode(correction, w);
        bodeGainNew = squeeze(bodeGainNew)';
        bodePhaseNew = deg2rad(squeeze(bodePhaseNew)');
        delta = [delta;...
                spec - reckoning(bodeGain.*bodeGainNew, bodePhase+bodePhaseNew, st)];
    end
end

% ...pole variations...
for i=1:size(varpoles,1)
    if imag(poles(i)) > 0 % this is a complex pole that was already cared for
        continue % skip this pole
    end
    for j=1:2
        if imag(poles(i)) == 0
            correction = zpk(poles(i), poles(i)+varpoles(i,j), 1,...
                Ts, 'Variable', variable);
        else
            correction = zpk([poles(i)+varpoles(i,j)...
                conj(poles(i))+conj(varpoles(i,j))],...
                [poles(i) conj(poles(i))], 1, Ts, 'Variable', variable);
        end
        [bodeGainNew, bodePhaseNew] = bode(correction, w);
        bodeGainNew = squeeze(bodeGainNew)';
        bodePhaseNew = deg2rad(squeeze(bodePhaseNew)');
        delta = [delta;...
                spec - reckoning(bodeGain.*bodeGainNew, bodePhase+bodePhaseNew, st)];
    end
end

% ...and finally the penalty function value
if st=='g'
    error = sum((delta.*(delta<0)).^2);
else
    error = sum((delta.*(delta>0)).^2);
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function performance = reckoning(gain, phase, st)
% gain - in absolute value
% phase - in rad
% performance - in dB (if st is 'g') or without dimension (if st is 'd')

if st=='g'
    performance = max(20 * log10(gain ./ sqrt(1+gain.^2+2*gain.*cos(phase))));
else
    performance = min(-cos(pi^2 ./...
        (2 * acos((gain.^2 + 2*gain.*(cos(phase)-1) + 1) ./ (2*gain)))));
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function error = crone3Aux2(x, yslope, spec, st)

% error = crone3Aux2(x, yslope, spec, st)
% This function is for finding the phase x rad/s at which a certain
% slope yslope dB/rad in the Nichols plane will be tangent to a curve
% corresponding to a certain closed-loop behaviour, specified by variables
% spec and st, as explained in crone3.
% Check the manual for further informations.
% Duarte Valério 2003

if st=='g'
    if (spec>1 & yslope>0) | spec<1
        yslopex = (20/log(10)) * (sin(x)+sin(2*x)/(2*sqrt((cos(x))^2-(1-1/(spec^2))))) / (-cos(x)-sqrt((cos(x))^2-(1-1/(spec^2))));
    elseif spec>1
        yslopex = (20/log(10)) * (sin(x)-sin(2*x)/(2*sqrt((cos(x))^2-(1-1/(spec^2))))) / (-cos(x)+sqrt((cos(x))^2-(1-1/(spec^2))));
    else % if spec==1
        yslopex = (20/log(10)) * tan(x);
    end
else
    temp = cos(x)-1-cos(pi^2/(2*acos(-spec)));
    if yslope>0
        yslopex = (20/log(10)) * (sin(x)+temp*sin(x)/sqrt(temp^2-1)) ./ (-temp-sqrt(temp^2-1));
    else % if yslope<0
        yslopex = (20/log(10)) * (sin(x)-temp*sin(x)./sqrt(temp.^2-1)) ./ (-temp+sqrt(temp^2-1));
    end
end
error = (yslopex - yslope)^2;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function error = crone3Aux3(order, yslope, x, y)

% This function is for finding the complex order of differentiation (a+jb),
% given in variable order, that will have in the Nichols plane a slope
% yslope dB/dec while passing through point (x rad; y dB).
% Check the manual for further informations.
% Duarte Valério 2003

a = order(1);
b = order(2);
if b<0 % negative slope phase
    error = (yslope - 20*a / (-b*log(10)*tanh(b*pi/2)))^2 +...
        (a*pi/2 - y + x*yslope - yslope*20*log10(cosh(b*pi/2)))^2;
else % positive slope phase
    error = (yslope + 20*a / (-b*log(10)*tanh(b*pi/2)))^2 +...
        (a*pi/2 - y + x*yslope - yslope*20*log10(cosh(b*pi/2)))^2;
end