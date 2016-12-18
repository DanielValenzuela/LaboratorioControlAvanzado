fun = @(x) IAE(x);
parameters;

if ControllerType == 0
	%-------------------- Funcion Objetivo PIDOF --------------------
	nvars = 3;
	lb = 0;
	ub = 0.9;
elseif ControllerType == 1	%PID
	%-------------------- Funcion Objetivo PID --------------------
	nvars = 3;
	lb = 0;
	ub = 300;
elseif ControllerType == 2
	%-------------------- Funcion Objetivo PIOF --------------------
	nvars = 3;
	lb = 0;
	ub = 300;
else
	%-------------------- Funcion Objetivo PI --------------------
	nvars = 2;
	lb = 0;
	ub = 300;
end

psoOptions = get_psoOptions;
psoOptions.Vars.Dim = nvars
psoOptions.Vars.Iterations = 50;
psoOptions.Vars.SwarmSize = 30;

psoOptions.Obj.f2eval = fun;
psoOptions.Obj.lb = lb; %[-1.5; -2];
psoOptions.Obj.ub = ub; %[2; 2];

[tfxmin, xmin, Swarm, tHistory] = pso(psoOptions);