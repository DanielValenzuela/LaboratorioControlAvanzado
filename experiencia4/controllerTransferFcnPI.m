function transferFcn = controllerTransferFcnPI(params, w)
	parameters;

	%Controller parameters
	Kp = params(1);
	Ki = params(2);

	%Transfers functions
	C_jw = (Kp-1j*Ki/(w));
	transferFcn = C_jw;
end