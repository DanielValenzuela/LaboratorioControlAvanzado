function transferFcn = controllerTransferFcn(params, w)
	parameters;

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