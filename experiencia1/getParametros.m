close all;
%clear
clc
load('datosExp1.mat');
%Constantes
H = 34.5;  %[cm]
R = 78.9;  %[cm]
Ts = 0.01;  %[s]
Fs = 1/Ts; %[Hz]
%------------------
frecuencias = (30:17.5:100)';
alturas1 = nivel1;
alturas2 = nivel2;
alturas3 = nivel3;
alturas4 = nivel4;
alturas5 = nivel5;
h_datas = struct('alturas1',alturas1,'alturas2',alturas2,'alturas3',alturas3,'alturas4',alturas4,'alturas5',alturas5);
limites = [[20 40];[30 60];[30 60];[30 60];[30 60]];

%grafico de valores no filtrados
figure('Name','alturas NO filtradas','NumberTitle','off');
for i=1:length(frecuencias)
    i_dato = strcat('alturas',int2str(i));
    subplot(2,3,i); plot(h_datas.(i_dato).signals.values, 'r');
    %xlim([1.45 1.5])
    title(strcat('Grafico de alturas con frecuencia',int2str(i),',  NO filtradas'))
    xlabel('Tiempo [s]'); ylabel('Altura [cm], h(t)');
end

h_datas_filtradas = struct('filt1',[],'filt2',[],'filt3',[],'filt4',[],'filt5',[]);
h_times = struct('t1',[],'t2',[],'t3',[],'t4',[],'t5',[]);

figure('Name','alturas filtradas','NumberTitle','off');
for i=1:length(frecuencias)
    i_altura = strcat('alturas',int2str(i));
    i_time = strcat('t',int2str(i));
    i_filt = strcat('filt',int2str(i));
    [auxH, auxT] = myFilt(h_datas.(i_altura), limites(i,1), limites(i,2));
    h_datas_filtradas.(i_filt) = auxH;
    h_times.(i_time) = auxT;
    subplot(2,3,i); plot(h_datas_filtradas.(i_filt), 'b');
    %xlim([1.45 1.5])
    title(strcat('Grafico de alturas con frecuencia',int2str(i),',  filtradas'))
    xlabel('Tiempo [s]'); ylabel('Altura [cm], h(t)');
end

volumenesMatrix = struct('v1',[],'v2',[],'v3',[],'v4',[],'v5',[]);

for i=1:length(frecuencias)
    i_filt = strcat('filt',int2str(i));
    i_volumen = strcat('v',int2str(i));
    i_time = strcat('t',int2str(i));
    dh = [diff(h_datas_filtradas.(i_filt))./Ts];
    dh = [dh;dh(length(dh))];
    flujo_t = (pi*(R^2)/(H^2))*(h_datas_filtradas.(i_filt).^2).*dh;
    volumenesMatrix.(i_volumen) = flujo_t;
    %Graficos en tiempo y frecuencia del flujo
    [flujo_f, flujo_S] = Fourier(flujo_t, Fs);
    graficarEnTyF(h_times.(i_time), flujo_t, flujo_f, flujo_S,' Flujo'); % Grafico
end

%figure('Name','Flujos en el tiempo','NumberTitle','off');
for i=1:length(frecuencias)
    i_volumen = strcat('v',int2str(i));
    i_time = strcat('t',int2str(i));
    FlujosProm(i) = mean(volumenesMatrix.(i_volumen));
    
    %Filtro pasa bajos
    %flujoFiltrado_t = filtroPasaBajos(volumenesMatrix.(i_volumen), Fs);
    flujoFiltrado_t = filtroPasaBanda(volumenesMatrix.(i_volumen), Fs, [30 40], [10 45]);
    %Graficos en tiempo y frecuencia del flujo Filtrado
    [flujoFiltrado_f, flujoFiltrado_S] = Fourier(flujoFiltrado_t, Fs);
    graficarEnTyF(h_times.(i_time), flujoFiltrado_t, flujoFiltrado_f, flujoFiltrado_S,' Flujo filtrado'); % Grafico
    
    %subplot(2,3,i); plot(volumenesMatrix.(i_volumen), 'b');
    %%xlim([1.45 1.5])
    %title(strcat('Grafico de Flujos con frecuencia de bomaba constante de  ',int2str(frecuencias(i)),',%'))
    %xlabel('Tiempo [s]'); ylabel('Flujo [cm], [cm/s?], Fin(t)');
end

figure('Name','Flujos Promedio','NumberTitle','off');
plot(frecuencias,FlujosProm, 'bo-');
%xlim([1.45 1.5])
title('Grafico de Flujos Promedio para diferentes frecuencias de la bomba')
xlabel('Frecuencia de la bomba [%]'); ylabel('Flujo de Entrada [cm3/s?], Fin');

%volumnes_prom = mean(volumenes_matrix);