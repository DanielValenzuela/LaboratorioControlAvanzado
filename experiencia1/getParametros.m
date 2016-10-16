<<<<<<< HEAD
close all;
clear
clc
load('datosExp1.mat');
%Constantes
H = 79.8;  %[cm]
R = 34.5;  %[cm]
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
    subplot(2,3,i); plot(h_datas.(i_dato).time,h_datas.(i_dato).signals.values, 'r');
    %xlim([1.45 1.5])
    title(strcat('Grafico de alturas con frecuencia',int2str(i),',  NO filtradas'))
    xlabel('Tiempo [s]'); ylabel('Altura [cm], h(t)');
end

subMuestH = struct('signal',[],'time',[]);
h_datas_filtradas = struct('filt1',[],'filt2',[],'filt3',[],'filt4',[],'filt5',[]);
h_times = struct('t1',[],'t2',[],'t3',[],'t4',[],'t5',[]);

%figure('Name','alturas filtradas','NumberTitle','off');
for i=1:length(frecuencias)
    i_altura = strcat('alturas',int2str(i));
    i_time = strcat('t',int2str(i));
    i_filt = strcat('filt',int2str(i));

    %Graficos en tiempo y frecuencia de altura NO Filtrada
    [alturas_f, alturas_S] = Fourier(h_datas.(i_altura).signals.values, Fs);
    graficarEnTyF(h_datas.(i_altura).time, h_datas.(i_altura).signals.values, alturas_f, alturas_S,strcat(' alturas con fBomba[%]= ',int2str(frecuencias(i)))); % Grafico

    alturasFiltradas_t = filtroPasaBajos(h_datas.(i_altura).signals.values, Fs, [2], [20]);
    %Graficos en tiempo y frecuencia de altura NO Filtrada
    [alturasFiltradas_f, alturasFiltradas_S] = Fourier(alturasFiltradas_t, Fs);
    graficarEnTyF(h_datas.(i_altura).time, alturasFiltradas_t, alturasFiltradas_f, alturasFiltradas_S, strcat(' alturas Filtradas con fBomba[%]= ',int2str(frecuencias(i)))); % Grafico

    %[subMuestH.signal, subMuestH.time] = subMuest(h_datas.(i_altura), 1);
    subMuestH.signal = alturasFiltradas_t;
    subMuestH.time = h_datas.(i_altura).time;
    [auxH, auxT] = myFilt(subMuestH, limites(i,1), limites(i,2));
    h_datas_filtradas.(i_filt) = auxH;
    h_times.(i_time) = auxT;
end

figure('Name','alturas Recortadas','NumberTitle','off');
for i=1:length(frecuencias)
    i_filt = strcat('filt',int2str(i));
    subplot(2,3,i); plot(h_datas_filtradas.(i_filt), 'b');
    %xlim([1.45 1.5])
    title(strcat('Grafico de alturas con fBomba[%]= ',int2str(frecuencias(i)),',  Recortadas'))
    xlabel('Tiempo [s]'); ylabel('Altura [cm], h(t)');
end

volumenesMatrix = struct('v1',[],'v2',[],'v3',[],'v4',[],'v5',[]);

for i=1:length(frecuencias)
    i_filt = strcat('filt',int2str(i));
    i_volumen = strcat('v',int2str(i));
    i_time = strcat('t',int2str(i));
    %dh = [myDiff(h_datas_filtradas.(i_filt), 4)];
    dh = [diff(h_datas_filtradas.(i_filt))];
    dt = h_times.(i_time)(2)-h_times.(i_time)(1);
    %dt = Ts*10;
    dh_dt = dh./dt;
    dh_dt = [dh_dt dh_dt(length(dh_dt))];
    %dh_dt = abs(dh_dt);
    flujo_t = (pi*(R^2)/(H^2))*(h_datas_filtradas.(i_filt).^2).*dh_dt;
    volumenesMatrix.(i_volumen) = flujo_t;
    %Graficos en tiempo y frecuencia del flujo
    [flujo_f, flujo_S] = Fourier(flujo_t', Fs);
    graficarEnTyF(h_times.(i_time), flujo_t, flujo_f, flujo_S,strcat(' Flujos con fBomba[%]= ',int2str(frecuencias(i)))); % Grafico
end

for i=1:length(frecuencias)
    i_volumen = strcat('v',int2str(i));
    i_time = strcat('t',int2str(i));
    %Filtro pasa bajos
    %flujoFiltrado_t = filtroPasaBajos(volumenesMatrix.(i_volumen), Fs);
    %flujoFiltrado_t = filtroPasaBanda(volumenesMatrix.(i_volumen), Fs, [30 40], [10 45]);
    flujoFiltrado_t = filtroPasaBajos(volumenesMatrix.(i_volumen), Fs, [1], [10]);
    %Graficos en tiempo y frecuencia del flujo Filtrado
    [flujoFiltrado_f, flujoFiltrado_S] = Fourier(flujoFiltrado_t', Fs);
    graficarEnTyF(h_times.(i_time), flujoFiltrado_t, flujoFiltrado_f, flujoFiltrado_S,strcat(' Flujos Filtrados con fBomba[%]= ',int2str(frecuencias(i)))); % Grafico
    %FlujosProm(i) = mean(volumenesMatrix.(i_volumen));
    FlujosProm(i) = mean(flujoFiltrado_t);
    
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

=======
close all;
clear
clc
load('datosExp1.mat');
%Constantes
H = 79.8;  %[cm]
R = 34.5;  %[cm]
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
    subplot(2,3,i); plot(h_datas.(i_dato).time,h_datas.(i_dato).signals.values, 'r');
    %xlim([1.45 1.5])
    title(strcat('Grafico de alturas con frecuencia',int2str(i),',  NO filtradas'))
    xlabel('Tiempo [s]'); ylabel('Altura [cm], h(t)');
end

subMuestH = struct('signal',[],'time',[]);
h_datas_filtradas = struct('filt1',[],'filt2',[],'filt3',[],'filt4',[],'filt5',[]);
h_times = struct('t1',[],'t2',[],'t3',[],'t4',[],'t5',[]);

%figure('Name','alturas filtradas','NumberTitle','off');
for i=1:length(frecuencias)
    i_altura = strcat('alturas',int2str(i));
    i_time = strcat('t',int2str(i));
    i_filt = strcat('filt',int2str(i));

    %Graficos en tiempo y frecuencia de altura NO Filtrada
    [alturas_f, alturas_S] = Fourier(h_datas.(i_altura).signals.values, Fs);
    graficarEnTyF(h_datas.(i_altura).time, h_datas.(i_altura).signals.values, alturas_f, alturas_S,strcat(' alturas con fBomba[%]= ',int2str(frecuencias(i)))); % Grafico

    alturasFiltradas_t = filtroPasaBajos(h_datas.(i_altura).signals.values, Fs, [2], [20]);
    %Graficos en tiempo y frecuencia de altura NO Filtrada
    [alturasFiltradas_f, alturasFiltradas_S] = Fourier(alturasFiltradas_t, Fs);
    graficarEnTyF(h_datas.(i_altura).time, alturasFiltradas_t, alturasFiltradas_f, alturasFiltradas_S, strcat(' alturas Filtradas con fBomba[%]= ',int2str(frecuencias(i)))); % Grafico

    %[subMuestH.signal, subMuestH.time] = subMuest(h_datas.(i_altura), 1);
    subMuestH.signal = alturasFiltradas_t;
    subMuestH.time = h_datas.(i_altura).time;
    [auxH, auxT] = myFilt(subMuestH, limites(i,1), limites(i,2));
    h_datas_filtradas.(i_filt) = auxH;
    h_times.(i_time) = auxT;
end

figure('Name','alturas Recortadas','NumberTitle','off');
for i=1:length(frecuencias)
    i_filt = strcat('filt',int2str(i));
    subplot(2,3,i); plot(h_datas_filtradas.(i_filt), 'b');
    %xlim([1.45 1.5])
    title(strcat('Grafico de alturas con fBomba[%]= ',int2str(frecuencias(i)),',  Recortadas'))
    xlabel('Tiempo [s]'); ylabel('Altura [cm], h(t)');
end

volumenesMatrix = struct('v1',[],'v2',[],'v3',[],'v4',[],'v5',[]);

for i=1:length(frecuencias)
    i_filt = strcat('filt',int2str(i));
    i_volumen = strcat('v',int2str(i));
    i_time = strcat('t',int2str(i));
    %dh = [myDiff(h_datas_filtradas.(i_filt), 4)];
    dh = [diff(h_datas_filtradas.(i_filt))];
    dt = h_times.(i_time)(2)-h_times.(i_time)(1);
    %dt = Ts*10;
    dh_dt = dh./dt;
    dh_dt = [dh_dt dh_dt(length(dh_dt))];
    %dh_dt = abs(dh_dt);
    flujo_t = (pi*(R^2)/(H^2))*(h_datas_filtradas.(i_filt).^2).*dh_dt;
    volumenesMatrix.(i_volumen) = flujo_t;
    %Graficos en tiempo y frecuencia del flujo
    [flujo_f, flujo_S] = Fourier(flujo_t', Fs);
    graficarEnTyF(h_times.(i_time), flujo_t, flujo_f, flujo_S,strcat(' Flujos con fBomba[%]= ',int2str(frecuencias(i)))); % Grafico
end

for i=1:length(frecuencias)
    i_volumen = strcat('v',int2str(i));
    i_time = strcat('t',int2str(i));
    %Filtro pasa bajos
    %flujoFiltrado_t = filtroPasaBajos(volumenesMatrix.(i_volumen), Fs);
    %flujoFiltrado_t = filtroPasaBanda(volumenesMatrix.(i_volumen), Fs, [30 40], [10 45]);
    flujoFiltrado_t = filtroPasaBajos(volumenesMatrix.(i_volumen), Fs, [1], [10]);
    %Graficos en tiempo y frecuencia del flujo Filtrado
    [flujoFiltrado_f, flujoFiltrado_S] = Fourier(flujoFiltrado_t', Fs);
    graficarEnTyF(h_times.(i_time), flujoFiltrado_t, flujoFiltrado_f, flujoFiltrado_S,strcat(' Flujos Filtrados con fBomba[%]= ',int2str(frecuencias(i)))); % Grafico
    %FlujosProm(i) = mean(volumenesMatrix.(i_volumen));
    FlujosProm(i) = mean(flujoFiltrado_t);
    
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

>>>>>>> develop
%volumnes_prom = mean(volumenes_matrix);