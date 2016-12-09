function [c,ceq] = nonlconstr(params)
	parameters;

	%Constraints tolerances
	e1 = 10;
	e2 = 10;
	e3 = 10;
	e4 = 10;

	%Controller Transfers functions
	C_jwcg = controllerTransferFcn(params, wcg);
	C_jwh = controllerTransferFcn(params, wh);
	C_jwl = controllerTransferFcn(params, wl);
	
	%System Transfers functions
	G_jwcg = numG/(1j*wcg-poloG);
	G_jwh = numG/(1j*wh-poloG);
	G_jwl = numG/(1j*wl-poloG);

	%derivative restriction
	% syms w;
	% f(w) = angle(controllerTransferFcn(params, w)*numG/(j*w-poloG));
	% derivative_restriction = subs(diff(f, w), wcg)


	%Constraints
	% c = [abs(angle(C_jwcg*G_jwcg)+pi-phi_m)-e1;
	% 	 %abs(simple(derivative_restriction))-e2;
	% 	 abs((C_jwh*G_jwh)/(1+C_jwh*G_jwh))-H-e3;
	% 	 abs(1/(1+C_jwl*G_jwl))-N-e4];
	c = [];
	ceq = [];
end