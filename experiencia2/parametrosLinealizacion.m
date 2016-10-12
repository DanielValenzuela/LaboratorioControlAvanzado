
%Valores de los parámetros
g = 9.81;	%[m/s^2]
M = 0.768;	%[Kg]
m = 0.104;	%[Kg]
l = 0.3213;	%[m]
b = 0.05;	%[Ns/m]
I = 0.0138;	%[Kg m^2]

b_prima = b+0.548;
% F_prima=1.88*u-4.7;

dPhi3_dx2 = g*[((M+m)*(I+m*l^2))/((M+m)*(I+m*l^2)-(m^2)*(l^2))-1];
dPhi3_dx3 = [(-b_prima*(I+m*l^2))/((M+m)*(I+m*(l^2))-(m^2)*(l^2))];
dPhi3_dx4 = 0;
dPhi4_dx2 = [((M+m)*m*g*l)/((M+m)*(I+m*(l^2))-(m^2)*(l^2))];
dPhi4_dx3 = [(-m*l*b_prima)/((M+m)*(I+m*(l^2))-(m^2)*(l^2))];
dPhi4_dx4 = 0;


dPhi3_dF = 1.88*(I+m*(l^2))/((M+m)*(I+m*(l^2))-(m^2)*(l^2));
dPhi4_dF = (1.88*m*l)/((M+m)*(I+m*(l^2))-(m^2)*(l^2));

%Mostrar valores en consola
% dPhi3_dx2
% dPhi3_dx3
% dPhi3_dx4
% dPhi4_dx2
% dPhi4_dx3
% dPhi4_dx4

dPhi3_dF
dPhi4_dF