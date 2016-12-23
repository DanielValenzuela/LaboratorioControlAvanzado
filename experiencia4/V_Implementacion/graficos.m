%% Graficos

cd('..')
% load('datos/III3_PIDOF.mat')
% load('datos/III_actividad4_PID.mat')
load('datos/III_actividad4_PIOF.mat')
cd('V_Implementacion/')

sim('bandas')
clc

% name = 'PIDOF sintonizado en Frecuencia, Implementación en Planta';
% name = 'PID sintonizado en Frecuencia, Implementación en Planta';
name = 'PIOF sintonizado en Frecuencia, Implementación en Planta';
% name = 'PI sintonizado en Frecuencia, Implementación en Planta';

% hc = sensorNoiseFilter(h);
hc = filtroPasaBajos(h(:,2), 1/0.01, [1], [2]);

figure('Name', name,'NumberTitle','off');
% plot(bandas.time, bandas.signals.values(:,1), 'k', bandas.time, bandas.signals.values(:,2), 'k', hc.time, hc.signal_values, 'b', II3_referencia_PIDOF.time, II3_referencia_PIDOF.signals.values, 'r')
% plot(bandas.time, bandas.signals.values(:,1), 'k', bandas.time, bandas.signals.values(:,2), 'k', h(:,1), h(:,2), 'b', II3_referencia_PIDOF.time, II3_referencia_PIDOF.signals.values, 'r', hc.time, hc.signal_values, 'g')
% plot(bandas.time, bandas.signals.values(:,1), 'k', bandas.time, bandas.signals.values(:,2), 'k', h(:,1), h(:,2), 'b', II3_referencia_PIDOF.time, II3_referencia_PIDOF.signals.values, 'r', h(:,1), hc, 'g')
plot(h(:,1), hc, 'b', bandas.time, bandas.signals.values(:,1), 'k', bandas.time, bandas.signals.values(:,2), 'k', II3_referencia_PIDOF.time, II3_referencia_PIDOF.signals.values, 'r')
set(gca,'fontsize',14)
title(name, 'fontsize', 18)
xlabel('Tiempo [s]', 'fontsize', 18); ylabel('Altura [cm]', 'fontsize', 18);
legend('Altura', 'Banda 2%', 'Banda 2%', 'Referencia')

% [h_f, h_S] = Fourier(h(:,2), 1/0.01);
% graficarEnTyF(h(:,1), h(:,2), h_f, h_S, 'Altura');