function derivative_restriction = restriction2(params)

	parameters;

	syms w;

	%Controller Transfers functions
	if ControllerType == 0
		%-------------------- Funcion Objetivo PIDOF --------------------
		 Controller = controllerTransferFcn(params, w, 'rectangular');
	elseif ControllerType == 1
		%-------------------- Funcion Objetivo PID --------------------
		Controller = controllerTransferFcnPID(params, w, 'rectangular');
	elseif ControllerType == 2
		%-------------------- Funcion Objetivo PIOF --------------------
		Controller = controllerTransferFcnPIOF(params, w, 'rectangular');
	else
		%-------------------- Funcion Objetivo PI --------------------
		Controller = controllerTransferFcnPI(params, w, 'rectangular');
	end

	C_real = Controller(1);
	C_imag = Controller(2);

	%System Transfer function
	G_real = (numG*poloG)/(w^2+poloG^2);
	G_imag = (-numG*w)/(w^2+poloG^2);

	%Calcs
	imag_real = (C_real*G_imag+C_imag*G_real)/(C_real*G_real-C_imag*G_imag);

	f(w) = (1/(1+imag_real^2))*diff(imag_real,w);

	derivative_restriction = subs(f(w), wcg);
end