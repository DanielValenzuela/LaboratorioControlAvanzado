fun = @(x) IAE(x);
parameters;
maxGain = inf;

if ControllerType == 0
    %-------------------- Funcion Objetivo PIDOF --------------------
    nvars = 5;
    % Limites de parametros
    lb = [0,0,0.75,0,0];
    ub = [maxGain,maxGain,1,maxGain,0.25];
    initialPoint = [75; 2.5; 0.87; 2.5; 0.12];
elseif ControllerType == 1  %PID
    %-------------------- Funcion Objetivo PID --------------------
    nvars = 3;
    % Limites de parametros
    lb = [0,0,0];
    ub = [maxGain,maxGain,maxGain];
    initialPoint = [75; 2.5; 2.5];
elseif ControllerType == 2
    %-------------------- Funcion Objetivo PIOF --------------------
    nvars = 3;
    % Limites de parametros
    lb = [0,0,0.75];
    ub = [maxGain,maxGain,1];
    initialPoint = [75; 2.5; 0.87];
else
    %-------------------- Funcion Objetivo PI --------------------
    nvars = 2;
    % Limites de parametros
    lb = [0,0];
    ub = [maxGain,maxGain];
    initialPoint = [75; 2.5];
end

options = optimoptions('particleswarm','Display','Off', 'InitialSwarmSpan', initialPoint, 'SwarmSize',30,'MaxIter',50);
% options = optimoptions('particleswarm','Display','Off', 'SwarmSize',30,'MaxIter',50);
tic
[x,fval,exitflag,output] = particleswarm(fun,nvars,lb,ub,options);
toc