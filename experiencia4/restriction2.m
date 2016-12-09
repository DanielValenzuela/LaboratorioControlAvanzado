function derivative_restriction = restriction2(params)

	parameters;

	%Controller parameters
	Kp = params(1);
	Ki = params(2);
	lambda = params(3);
	Kd = params(4);
	mu = params(5);

	syms w;

	%Controller Transfer function
	Ki_OF_real = (Ki/(w^lambda))*cos(pi*lambda/2);
	Ki_OF_imag = -(Ki/(w^lambda))*sin(pi*lambda/2);
	Kd_OF_real = (Kd*w^mu)*cos(pi*mu/2);
	Kd_OF_imag = (Kd*w^mu)*sin(pi*mu/2);

	C_real = (Kp+Ki_OF_real+Kd_OF_real);
	C_imag = (Kp+Ki_OF_imag+Kd_OF_imag);

	%System Transfer function
	G_real = (numG*poloG)/(w^2+poloG^2);
	G_imag = (-numG*w)/(w^2+poloG^2);

	%Calcs
	imag_real = (C_real*G_imag+C_imag*G_real)/(C_real*G_real-C_imag*G_imag);

	f(w) = (1/(1+imag_real^2))*diff(imag_real,w);

	derivative_restriction = subs(f(w), wcg);
end