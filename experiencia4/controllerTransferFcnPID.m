function transferFcn = controllerTransferFcnPID(params, w)
	parameters;

	%Controller parameters
	Kp = params(1);
	Ki = params(2);
	Kd = params(3);

	%Transfers functions
	C_jw = (Kp-1j*Ki/(w)+1j*Kd*w);
	transferFcn = C_jw;
end