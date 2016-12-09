function fun = objectiveFuncPID(params)
	parameters;

	controllerType = 1;		% 0:PIDOF, 1:PID, 2: ..., 3:...

	%controller parameters
	Kp = params(1);
	Ki = params(2);
	Kd = params(3);

	C_jw = (Kp-1j*Ki/(wcg)+1j*Kd*wcg);
	G_jw = numG/(1j*wcg-poloG);

	fun = abs(abs(C_jw*G_jw)-1);
end