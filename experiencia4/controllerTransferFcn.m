function transferFcn = controllerTransferFcn(params, w)
	%Design especifications for frecuency tunning of PIDOF controller

	wcg = 0.73;		%[rad/s]
	phi_m = 69.89;	%[°]
	wh = 10;		%[rad/s]
	H = -10;		%[dB]
	wl = 0.01;		%[rad/s]
	N = -20;		%[dB]

	%Linearised system parameters. System Form: G(s) = numG/(s-poloG)

	numG = 0.0040;
	poloG = -0.0012;

	%Controller parameters
	Kp = params(1);
	Ki = params(2);
	lambda = params(3);
	Kd = params(4);
	mu = params(5);

	%Transfers functions
	Ki_OF = (Ki/(w^lambda))*(cos(pi*lambda/2)-1j*sin(pi*lambda/2));
	Kd_OF = (Kd*w^mu)*(cos(pi*mu/2)+1j*sin(pi*mu/2));
	C_jw = (Kp+Ki_OF+Kd_OF);
	transferFcn = C_jw;
end