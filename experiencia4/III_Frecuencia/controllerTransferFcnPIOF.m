function transferFcn = controllerTransferFcnPIOF(params, w, form)
	parameters;

	%Controller parameters
	Kp = params(1);
	Ki = params(2);
	lambda = params(3);

	if (strcmp(form, 'paralela'))
		%Controller Transfers functions
		Ki_OF = (Ki/(w^lambda))*(cos(pi*lambda/2)-1j*sin(pi*lambda/2));
		C_jw = (Kp+Ki_OF);
		transferFcn = C_jw;
	elseif (strcmp(form, 'rectangular'))
		%Controller Transfer function
		Ki_OF_real = (Ki/(w^lambda))*cos(pi*lambda/2);
		Ki_OF_imag = -(Ki/(w^lambda))*sin(pi*lambda/2);

		C_real = (Kp+Ki_OF_real);
		C_imag = (Ki_OF_imag);

		transferFcn = [C_real, C_imag];
end