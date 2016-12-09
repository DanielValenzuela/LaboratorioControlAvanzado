function [c,ceq] = nonlconstr(params)
	parameters;

	%Constraints tolerances
	e1 = 70;
	e2 = 1;
	e3 = 15;
	e4 = 25;

	%Controller type
	ControllerType = 3;	%	0:PIDOF,	1:PID,		2:PIOF,		3:PI

	%Controller Transfers functions
	if ControllerType == 0		%PIDOF
		C_jwcg = controllerTransferFcn(params, wcg);
		C_jwh = controllerTransferFcn(params, wh);
		C_jwl = controllerTransferFcn(params, wl);
	elseif ControllerType == 1
		C_jwcg = controllerTransferFcnPID(params, wcg);
		C_jwh = controllerTransferFcnPID(params, wh);
		C_jwl = controllerTransferFcnPID(params, wl);
	elseif ControllerType == 2
		C_jwcg = controllerTransferFcnPIOF(params, wcg);
		C_jwh = controllerTransferFcnPIOF(params, wh);
		C_jwl = controllerTransferFcnPIOF(params, wl);
	else
		C_jwcg = controllerTransferFcnPI(params, wcg);
		C_jwh = controllerTransferFcnPI(params, wh);
		C_jwl = controllerTransferFcnPI(params, wl);
	end
	
	%System Transfers functions
	G_jwcg = numG/(1j*wcg-poloG);
	G_jwh = numG/(1j*wh-poloG);
	G_jwl = numG/(1j*wl-poloG);

	%Constraints
	c = [abs(angle(C_jwcg*G_jwcg)+pi-phi_m)-e1;
		 %abs(restriction2(params))-e2;
		 abs((C_jwh*G_jwh)/(1+C_jwh*G_jwh))-H-e3;
		 abs(1/(1+C_jwl*G_jwl))-N-e4];
	% c = [];
	ceq = [];
end