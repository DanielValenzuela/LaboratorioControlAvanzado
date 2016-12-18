function [c,ceq] = nonlconstr(params)
	parameters;

	%Constraints tolerances
	e1 = 70;
	e2 = 1;
	e3 = 15;
	e4 = 25;

	%Controller Transfers functions
	if ControllerType == 0
		%-------------------- Funcion Objetivo PIDOF --------------------
		C_jwcg = controllerTransferFcn(params, wcg, 'paralela');
		C_jwh = controllerTransferFcn(params, wh, 'paralela');
		C_jwl = controllerTransferFcn(params, wl, 'paralela');
	elseif ControllerType == 1
		%-------------------- Funcion Objetivo PID --------------------
		C_jwcg = controllerTransferFcnPID(params, wcg, 'paralela');
		C_jwh = controllerTransferFcnPID(params, wh, 'paralela');
		C_jwl = controllerTransferFcnPID(params, wl, 'paralela');
	elseif ControllerType == 2
		%-------------------- Funcion Objetivo PIOF --------------------
		C_jwcg = controllerTransferFcnPIOF(params, wcg, 'paralela');
		C_jwh = controllerTransferFcnPIOF(params, wh, 'paralela');
		C_jwl = controllerTransferFcnPIOF(params, wl, 'paralela');
	else
		%-------------------- Funcion Objetivo PI --------------------
		C_jwcg = controllerTransferFcnPI(params, wcg, 'paralela');
		C_jwh = controllerTransferFcnPI(params, wh, 'paralela');
		C_jwl = controllerTransferFcnPI(params, wl, 'paralela');
	end
	
	%System Transfers functions
	G_jwcg = numG/(1j*wcg-poloG);
	G_jwh = numG/(1j*wh-poloG);
	G_jwl = numG/(1j*wl-poloG);

	%Constraints
	c = [abs(angle(C_jwcg*G_jwcg)+pi-phi_m)-e1;
		 abs(restriction2(params))-e2;
		 abs((C_jwh*G_jwh)/(1+C_jwh*G_jwh))-H-e3;
		 abs(1/(1+C_jwl*G_jwl))-N-e4];
	% c = [];
	ceq = [];
end