close all;
clear
clc
load('lastDatos/salidaLazoCerrado3.mat');
load('lastDatos/salidaLazoCerrado2.mat');

%Constantes
Ts = 0.01;  %[s]
Fs = 1/Ts; %[Hz]

%%----------------------------------------------------------------------
%%----------------------------------------------------------------------

%Graficos en tiempo y frecuencia de salida (altura) NO Filtrada
signal_15_30 = struct('signal', salidaLazoCerrado3.signals.values(1:5520,2),'time', salidaLazoCerrado3.time(1:5520));
[alturas_f, alturas_S] = Fourier(signal_15_30.signal, Fs);
graficarEnTyF(signal_15_30.time, signal_15_30.signal, alturas_f, alturas_S, 'Close Loop System Out NOT Filtered, 15-30 cm');
%Filtro Pasa Bajos
alturasFiltradas_t = filtroPasaBajos(signal_15_30.signal, Fs, [1], [2]);
%Graficos en tiempo y frecuencia de salida (altura) Filtrada
[alturasFiltradas_f, alturasFiltradas_S] = Fourier(alturasFiltradas_t, Fs);
graficarEnTyF(signal_15_30.time, alturasFiltradas_t, alturasFiltradas_f, alturasFiltradas_S, ' Close Loop System Out Filtered, 15-30 cm');

realSystemOutputFiltered = struct('signal', alturasFiltradas_t,'time', signal_15_30.time);

%%----------------------------------------------------------------------
%%----------------------------------------------------------------------

%Graficos en tiempo y frecuencia de salida (altura) NO Filtrada
signal_30_45 = struct('signal', salidaLazoCerrado2.signals.values(1150:2730,2),'time', salidaLazoCerrado2.time(1150:2730));
[alturas_f, alturas_S] = Fourier(signal_30_45.signal, Fs);
graficarEnTyF(signal_30_45.time, signal_30_45.signal, alturas_f, alturas_S, 'Close Loop System Out NOT Filtered, 30-45 cm');
%Filtro Pasa Bajos
alturasFiltradas_t = filtroPasaBajos(signal_30_45.signal, Fs, [1], [2]);
%Graficos en tiempo y frecuencia de salida (altura) Filtrada
[alturasFiltradas_f, alturasFiltradas_S] = Fourier(alturasFiltradas_t, Fs);
graficarEnTyF(signal_30_45.time, alturasFiltradas_t, alturasFiltradas_f, alturasFiltradas_S, ' Close Loop System Out Filtered, 30-45 cm');

realSystemOutputFiltered = struct('signal', alturasFiltradas_t,'time', signal_30_45.time);