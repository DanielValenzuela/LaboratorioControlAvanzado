close all;
clear
clc
load('lastDatos/SystemPerformance1.mat');

%Constantes
Ts = 0.01;  %[s]
Fs = 1/Ts; %[Hz]

%%----------------------------------------------------------------------
%%----------------------------------------------------------------------

%Graficos en tiempo y frecuencia de salida (altura) NO Filtrada
[alturas_f, alturas_S] = Fourier(SystemPerformance1.signals.values, Fs);
graficarEnTyF(SystemPerformance1.time, SystemPerformance1.signals.values, alturas_f, alturas_S, 'Open Loop System Out NOT Filtered');

alturasFiltradas_t = filtroPasaBajos(SystemPerformance1.signals.values, Fs, [1], [5]);
%Graficos en tiempo y frecuencia de salida (altura) Filtrada
[alturasFiltradas_f, alturasFiltradas_S] = Fourier(alturasFiltradas_t, Fs);
graficarEnTyF(SystemPerformance1.time, alturasFiltradas_t, alturasFiltradas_f, alturasFiltradas_S, ' Open Loop System Out Filtered');

realSystemOutputFiltered = struct('signal', alturasFiltradas_t,'time', SystemPerformance1.time);