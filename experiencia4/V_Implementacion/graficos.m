%% Graficos

% load('datos/III3_PIDOF.mat')
% load('datos/III_actividad4_PID.mat')
load('datos/III_actividad4_PIOF.mat')
sim('bandas')
clc

name = 'PIOF, Implementación en Planta';
% name = 'PI, Implementación en Planta';
% name = 'PIOF, Implementación en Planta';
% name = 'PI, Implementación en Planta';


figure('Name', name,'NumberTitle','off');
plot(bandas.time, bandas.signals.values(:,1), 'k', bandas.time, bandas.signals.values(:,2), 'k', h(:,1), h(:,2), 'b', II3_referencia_PIDOF.time, II3_referencia_PIDOF.signals.values, 'r')
set(gca,'fontsize',14)
title(name, 'fontsize', 18)
xlabel('Tiempo [s]', 'fontsize', 18); ylabel('Altura [cm]', 'fontsize', 18);
legend('Banda 2%', 'Banda 2%', 'Altura', 'Referencia')