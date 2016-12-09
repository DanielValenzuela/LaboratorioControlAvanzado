function fun = objectiveFuncPI(params)
	parameters;

	controllerType = 1;		% 0:PIDOF, 1:PID, 2: ..., 3:...

	%controller parameters
	Kp = params(1);
	Ki = params(2);

	C_jw = (Kp-1j*Ki/(wcg));
	G_jw = numG/(1j*wcg-poloG);

	fun = abs(abs(C_jw*G_jw)-1);
end