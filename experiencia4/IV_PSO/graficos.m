%% Graficos

% cd('..')
% % load('datos/III3_PIDOF.mat')
% % load('datos/III_actividad4_PID.mat')
% load('datos/pso_datos_it1_PIDOF_refPedida_modelFixed.mat')
% cd('IV_PSO/')

% sim('bandas')
% clc

% name = 'Sintonización PIDOF mediante PSO. Parámetros Óptimos';
name = 'Sintonización PID mediante PSO. Parámetros Óptimos';
% name = 'Sintonización PIOF mediante PSO. Parámetros Óptimos';
% name = 'Sintonización PI mediante PSO. Parámetros Óptimos';

% hc = sensorNoiseFilter(h);
% hc = filtroPasaBajos(h(:,2), 1/0.01, [1], [2]);

figure('Name', name,'NumberTitle','off');
% plot(bandas.time, bandas.signals.values(:,1), 'k', bandas.time, bandas.signals.values(:,2), 'k', hc.time, hc.signals.values(:,2), 'r', hc.time, hc.signals.values(:,1), 'b')
plot(hc.time, hc.signals.values(:,2), 'r', hc.time, hc.signals.values(:,1), 'b')
set(gca,'fontsize',14)
title(name, 'fontsize', 18)
xlabel('Tiempo [s]', 'fontsize', 18); ylabel('Altura [cm]', 'fontsize', 18);
legend('Banda 2%', 'Banda 2%', 'Referencia', 'Altura')

% [h_f, h_S] = Fourier(h(:,2), 1/0.01);
% graficarEnTyF(h(:,1), h(:,2), h_f, h_S, 'Altura');