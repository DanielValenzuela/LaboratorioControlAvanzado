function transferFcn = controllerTransferFcnPIOF(params, w)
	parameters;

	%Controller parameters
	Kp = params(1);
	Ki = params(2);
	lambda = params(3);

	%Transfers functions
	Ki_OF = (Ki/(w^lambda))*(cos(pi*lambda/2)-1j*sin(pi*lambda/2));
	C_jw = (Kp+Ki_OF);
	transferFcn = C_jw;
end