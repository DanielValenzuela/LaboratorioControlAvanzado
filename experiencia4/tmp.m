parameters;
params = [10; 10; 0.1; 10; 0.1];

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

% arg = controllerTransferFcn(params, w)*numG/(1j*w-poloG)
% f(w) = atan(imag(arg)/real(arg))
f(w) = simple(atan((C_real*G_imag+C_imag*G_real)/(C_real*G_real-C_imag*G_imag)));
dw = simple(diff(f, 'w'))
derivative_restriction = subs(dw, 1)