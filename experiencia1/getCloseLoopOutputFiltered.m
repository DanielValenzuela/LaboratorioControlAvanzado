close all;
clear
clc
%load('lastDatos/salidaLazoCerrado3.mat');
%load('lastDatos/salidaLazoCerrado2.mat');
load('DATOS_MARTES/DATOS_BUENOS_10_30_1.mat');
load('DATOS_MARTES/DATOS_BUENOS_45_60_1.mat');
%Constantes
Ts = 0.01;  %[s]
Fs = 1/Ts; %[Hz]

%%----------------------------------------------------------------------
%--------------- 15-30 [cm] --------------------------------------------
%%----------------------------------------------------------------------
Limit1 = 8605;
%Graficos en tiempo y frecuencia de salida (altura) NO Filtrada
signal_15_30 = struct('signal', salida_15_30.signals.values(1:Limit1,2),'time', salida_15_30.time(1:Limit1));
[alturas_f, alturas_S] = Fourier(signal_15_30.signal, Fs);
graficarEnTyF(signal_15_30.time, signal_15_30.signal, alturas_f, alturas_S, 'Close Loop System Out NOT Filtered, 15-30 cm');
%Filtro Pasa Bajos
alturasFiltradas_t = filtroPasaBajos(signal_15_30.signal, Fs, [5], [10]);
%Graficos en tiempo y frecuencia de salida (altura) Filtrada
[alturasFiltradas_f, alturasFiltradas_S] = Fourier(alturasFiltradas_t, Fs);
graficarEnTyF(signal_15_30.time, alturasFiltradas_t, alturasFiltradas_f, alturasFiltradas_S, ' Close Loop System Out Filtered, 15-30 cm');

realSystemOutputFiltered_15_30 = struct('input', salida_15_30.signals.values(1:Limit1,1),'direct_input', Ctrl_15_30.signals.values(1:Limit1),'output', alturasFiltradas_t,'time', signal_15_30.time);

%%----------------------------------------------------------------------
%--------------- 45-60 [cm] --------------------------------------------
%%----------------------------------------------------------------------
Limit3 = length(salida_45_60.time);
%Graficos en tiempo y frecuencia de salida (altura) NO Filtrada
signal_45_60 = struct('signal', salida_45_60.signals.values(1:Limit3,2),'time', salida_45_60.time(1:Limit3));
[alturas_f, alturas_S] = Fourier(signal_45_60.signal, Fs);
graficarEnTyF(signal_45_60.time, signal_45_60.signal, alturas_f, alturas_S, 'Close Loop System Out NOT Filtered, 15-30 cm');
%Filtro Pasa Bajos
alturasFiltradas_t = filtroPasaBajos(signal_45_60.signal, Fs, [5], [10]);
%Graficos en tiempo y frecuencia de salida (altura) Filtrada
[alturasFiltradas_f, alturasFiltradas_S] = Fourier(alturasFiltradas_t, Fs);
graficarEnTyF(signal_45_60.time, alturasFiltradas_t, alturasFiltradas_f, alturasFiltradas_S, ' Close Loop System Out Filtered, 15-30 cm');

realSystemOutputFiltered_45_60 = struct('input', salida_45_60.signals.values(1:Limit3,1),'direct_input', Ctrl_45_60.signals.values(1:Limit3),'output', alturasFiltradas_t,'time', signal_45_60.time);

%%----------------------------------------------------------------------
%--------------- 30-45 [cm] --------------------------------------------
%%----------------------------------------------------------------------

% %Graficos en tiempo y frecuencia de salida (altura) NO Filtrada
% signal_30_45 = struct('signal', salidaLazoCerrado2.signals.values(1150:2730,2),'time', salidaLazoCerrado2.time(1150:2730));
% [alturas_f, alturas_S] = Fourier(signal_30_45.signal, Fs);
% graficarEnTyF(signal_30_45.time, signal_30_45.signal, alturas_f, alturas_S, 'Close Loop System Out NOT Filtered, 30-45 cm');
% %Filtro Pasa Bajos
% alturasFiltradas_t = filtroPasaBajos(signal_30_45.signal, Fs, [1], [2]);
% %Graficos en tiempo y frecuencia de salida (altura) Filtrada
% [alturasFiltradas_f, alturasFiltradas_S] = Fourier(alturasFiltradas_t, Fs);
% graficarEnTyF(signal_30_45.time, alturasFiltradas_t, alturasFiltradas_f, alturasFiltradas_S, ' Close Loop System Out Filtered, 30-45 cm');

% realSystemOutputFiltered_30_45 = struct('input', salidaLazoCerrado2.signals.values(1150:2730,1),'output', alturasFiltradas_t,'time', signal_30_45.time);
