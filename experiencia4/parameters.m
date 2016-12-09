%Design especifications for frecuency tunning of PIDOF controller

wcg = 0.73;		%[rad/s]
phi_m = 69.89;	%[°]
wh = 10;		%[rad/s]
H = -10;		%[dB]
wl = 0.01;		%[rad/s]
N = -20;		%[dB]

%Linearised system parameters. System Form: G(s) = numG/(s-poloG)

numG = 0.0040;
poloG = -0.0012;