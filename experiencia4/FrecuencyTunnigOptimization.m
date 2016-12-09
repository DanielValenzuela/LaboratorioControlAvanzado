% Funcion Objetivo
% fun  = @objectiveFunc;		%PIDOF
% fun  = @objectiveFuncPID;		%PID
% fun  = @objectiveFuncPIOF;	%PIOF
fun  = @objectiveFuncPI;		%PI

% % Limites de parametros del controlador PIDOF
% lb = [0,0,0.75,0,0];
% ub = [inf,inf,1,inf,0.25];

% Limites de parametros del controlador PID
% lb = [0,0,0];
% ub = [inf,inf,inf];

% % Limites de parametros del controlador PIOF
% lb = [0,0,0.75];
% ub = [inf,inf,1];

% % Limites de parametros del controlador PI
lb = [0,0];
ub = [inf,inf];

% Punto de partida busqueda de optimo
% initialPoint = [10; 10; 0.1; 10; 0.1];	%PIDOF
% initialPoint = [10; 10; 1];				%PID
% initialPoint = [10; 10; 0.1];				%PIOF
initialPoint = [10; 10];					%PI


% Declaracion de restricciones
nonlcon = @constraints;
% options = optimoptions(@fmincon, 'Algorithm', 'interior−point');
options = optimset('Algorithm','interior-point', 'MaxFunEvals', 3000, 'MaxIter', 3000); % run interior-point algorithm
% Solucion del problema de optimizacion

K = fmincon(@(params) fun(params), initialPoint, [], [], [], [], lb, ub, @(params) nonlconstr(params), options)