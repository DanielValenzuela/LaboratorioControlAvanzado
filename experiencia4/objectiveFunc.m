function fun = objectiveFunc(params)
	parameters;

	%controller parameters
	Kp = params(1);
	Ki = params(2);
	lambda = params(3);
	Kd = params(4);
	mu = params(5);

	Ki_OF = (Ki/(wcg^lambda))*(cos(pi*lambda/2)-1j*sin(pi*lambda/2));
	Kd_OF = (Kd*wcg^mu)*(cos(pi*mu/2)+1j*sin(pi*mu/2));
	C_jw = (Kp+Ki_OF+Kd_OF);
	G_jw = numG/(1j*wcg-poloG);

	fun = abs(abs(C_jw*G_jw)-1);
end