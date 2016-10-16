%Constantes
Ts = 0.01;  %[s]
Fs = 1/Ts; %[Hz]

%Graficos en tiempo y frecuencia del ruido
%noise = struct('signal', noise.signals.values,'time', noise.time);
[noise_f, noise_S] = Fourier(noise.signals.values, Fs);
graficarEnTyF(noise.time, noise.signals.values, noise_f, noise_S, 'Ruido Blanco Limitado en Banda');