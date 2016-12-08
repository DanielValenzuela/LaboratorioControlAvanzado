a1 = -0.0012;
h0 = 37.5;
a2 = 0.0040;
f0 = 32.06;

s = tf('s');
sys = a2/(s-a1);

w=logspace(-1,1);
bode(sys,w)
[mag, phase, w] = bode(sys,w);
[Mp, k] = max(mag);
pico_resonante = 20*log10(Mp)
frecuencia_resonante = w(k)
n=1;
while 20*log(mag(n))>=-3;n=n+1;
end
ancho_banda = w(n)