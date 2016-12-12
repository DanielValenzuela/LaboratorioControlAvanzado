function transferFcn = controllerTransferFcnPID(params, w, form)
	parameters;

	%Controller parameters
	Kp = params(1);
	Ki = params(2);
	Kd = params(3);

	if (strcmp(form, 'paralela'))
		%Controller Transfers functions
		C_jw = (Kp-1j*Ki/(w)+1j*Kd*w);
		transferFcn = C_jw;
	elseif (strcmp(form, 'rectangular'))
		%Controller Transfer function
		Ki_imag = -(Ki/w);
		Kd_imag = (Kd*w);

		C_real = (Kp);
		C_imag = (Ki_imag+Kd_imag);

		transferFcn = [C_real, C_imag];
end