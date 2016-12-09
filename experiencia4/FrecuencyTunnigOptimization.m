% Funcion Objetivo
% fun  = @objectiveFunc;

% Limites de parametros del controlador
lb = [0,0,0,0.75,0];
ub = [inf,inf,1,inf,0.25];

% Punto de partida busqueda de optimo
initialPoint = [10; 10; 0.1; 10; 0.1];

% Declaracion de restricciones
nonlcon = @constraints;
% options = optimoptions(@fmincon, 'Algorithm', 'interior−point');
options = optimset('Algorithm','interior-point', 'MaxFunEvals', 3000, 'MaxIter', 3000); % run interior-point algorithm
% Solucion del problema de optimizacion

K = fmincon(@(params) fun(params), initialPoint, [], [], [], [], lb, ub, @(params) nonlconstr(params), options)