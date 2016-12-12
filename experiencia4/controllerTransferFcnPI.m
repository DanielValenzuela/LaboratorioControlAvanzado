function transferFcn = controllerTransferFcnPI(params, w, form)
	parameters;

	%Controller parameters
	Kp = params(1);
	Ki = params(2);

	if (strcmp(form, 'paralela'))
		%Controller Transfers functions
		C_jw = (Kp-1j*Ki/(w));
		transferFcn = C_jw;
	elseif (strcmp(form, 'rectangular'))
		%Controller Transfer function
		Ki_imag = -(Ki/w);

		C_real = (Kp);
		C_imag = (Ki_imag);

		transferFcn = [C_real, C_imag];
end