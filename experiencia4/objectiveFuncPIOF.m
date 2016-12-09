function fun = objectiveFuncPIOF(params)
	parameters;

	controllerType = 1;		% 0:PIDOF, 1:PID, 2: ..., 3:...

	%controller parameters
	Kp = params(1);
	Ki = params(2);
	lambda = params(3);

	Ki_OF = (Ki/(wcg^lambda))*(cos(pi*lambda/2)-1j*sin(pi*lambda/2));
	C_jw = (Kp+Ki_OF);
	G_jw = numG/(1j*wcg-poloG);

	fun = abs(abs(C_jw*G_jw)-1);
end