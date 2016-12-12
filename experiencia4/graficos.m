%% Graficos

% name = 'PIDOF, Sintonización en Frecuencia';
% name = 'PID, Sintonización en Frecuencia';
name = 'PIOF, Sintonización en Frecuencia';
% name = 'PI, Sintonización en Frecuencia';


figure('Name', name,'NumberTitle','off');
plot(bandas.time, bandas.signals.values(:,1), 'k', bandas.time, bandas.signals.values(:,2), 'k', hc.time, hc.signals.values(:,1), 'b', hc.time, hc.signals.values(:,2), 'r')
set(gca,'fontsize',14)
title(name, 'fontsize', 18)
xlabel('Tiempo [s]', 'fontsize', 18); ylabel('Altura [cm]', 'fontsize', 18);