tic
%% Paramtros Necesarios
parameters;
maxGain = inf;

%% Funcion Objetivo y limites segun el tipo de controlador

if ControllerType == 0
	%-------------------- Funcion Objetivo PIDOF --------------------
	fun  = @objectiveFunc;
	% Limites de parametros
	lb = [0,0,0.75,0,0];
	ub = [maxGain,maxGain,1,maxGain,0.25];
	initialPoint = [10; 10; 0.75; 10; 0.1];
elseif ControllerType == 1	%PID
	%-------------------- Funcion Objetivo PID --------------------
	fun  = @objectiveFuncPID;
	% Limites de parametros
	lb = [0,0,0];
	ub = [maxGain,maxGain,maxGain];
	initialPoint = [10; 10; 1];
elseif ControllerType == 2
	%-------------------- Funcion Objetivo PIOF --------------------
	fun  = @objectiveFuncPIOF;
	% Limites de parametros
	lb = [0,0,0.75];
	ub = [maxGain,maxGain,1];
	initialPoint = [10; 10; 0.75];
else
	%-------------------- Funcion Objetivo PI --------------------
	fun  = @objectiveFuncPI;
	% Limites de parametros
	lb = [0,0];
	ub = [maxGain,maxGain];
	initialPoint = [10; 10];
end

% Declaracion de restricciones
nonlcon = @constraints;
% options = optimoptions(@fmincon, 'Algorithm', 'interior−point');
options = optimset('Algorithm','interior-point', 'MaxFunEvals', 3000, 'MaxIter', 3000); % run interior-point algorithm
% Solucion del problema de optimizacion

K = fmincon(@(params) fun(params), initialPoint, [], [], [], [], lb, ub, @(params) nonlconstr(params), options);
toc

showResults(K);