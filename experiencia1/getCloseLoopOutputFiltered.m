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


% %%----------------------------------------------------------------------
% %%----------------------------------------------------------------------

% %%Modelos ARX , ARIX  y ARMAX para 2 grupos de entrenamiento
% %%Importante: 1) El código no está probado
% %             2) compare devuelve un tipo, pero debería devolver una
% %             estructura iddata, por favor verificar esto en la versión
% %             nueva.

% %% ARX 15 a 30 [cm]

% y_train = realSystemOutputFiltered_15_30.output;
% u_train = realSystemOutputFiltered_15_30.input;
% t_train = realSystemOutputFiltered_15_30.time;
% z_train = iddata(y_train,u_train,0.1);


% NN = struc(1:3,1:3,1:3);

% V = arxstruc(z_train(1:2760),z_train(2761:end),NN); % entrenamiento y validacion en el mismo conjunto
% order = selstruc(V,0);

% for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% % generar el modelo ARX con los datos de entrenamiento para cada [na,nb,nk]
% model = arx(z_train,order);
% compare(z_train,model) % mostrar un grafico comparativo para los valores
% % reales y modelo ARX

% n(i,:) % mostrar [na,nb,nk]
% [y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARX 

% rmse(i) = sqrt(mean(y_train - y_est.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

% end
% figure
% plot(t_train,rmse);
% title('Error v/s tiempo (entre 15  30 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');

% %% ARX 30 a 45 [cm]

% y_train2 = realSystemOutputFiltered_30_45.output;
% u_train2 = realSystemOutputFiltered_30_45.input;
% t_train2 = realSystemOutputFiltered_30_45.time;
% z_train2 = iddata(y_train2,u_train2,0.1);

% NN = struc(1:3,1:3,1:3);

% V = arxstruc(z_train2(1:2760),z_train2(2761:end),NN);
% order = selstruc(V,0);

% for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% % generar el modelo ARX con los datos de entrenamiento para cada [na,nb,nk]
% model = arx(z_train2,order);
% compare(z_train2,model2) % mostrar un grafico comparativo para los valores
% % reales y modelo ARX

% n(i,:) % mostrar [na,nb,nk]
% [y_est2,fit2(i)] = compare(z_train2,model2); % encontrar el ajuste (fit) de cada modelo ARX 

% rmse2(i) = sqrt(mean(y_train2 - y_est2.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

% end
% figure
% plot(t_train2,rmse2);
% title('Error v/s tiempo (entre 30  45 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');

% %% ARIX 15 a 30 [cm]


% y_train = realSystemOutputFiltered_15_30.output;
% u_train = realSystemOutputFiltered_15_30.input;
% t_train = realSystemOutputFiltered_15_30.time;
% z_train = iddata(y_train,u_train,0.1);

% NN = struc(1:3,1:3,1:3);

% V = arxstruc(z_train(1:2760),z_train(2761:end),NN);
% order = selstruc(V,0);

% for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% % generar el modelo ARIX con los datos de entrenamiento para cada [na,nb,nk]
% model = arx(z_train,order,'IntegrateNoise',1);
% compare(z_train,model) % mostrar un grafico comparativo para los valores
% % reales y modelo ARIX

% n(i,:) % mostrar [na,nb,nk]
% [y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARIX 

% rmse(i) = sqrt(mean(y_train - y_est.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

% end
% figure
% plot(t_train,rmse);
% title('Error v/s tiempo (entre 15  30 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');

% %% ARXIX 30 a 45 [cm]

% y_train2 = realSystemOutputFiltered_30_45.output;
% u_train2 = realSystemOutputFiltered_30_45.input;
% t_train2 = realSystemOutputFiltered_30_45.time;
% z_train2 = iddata(y_train2,u_train2,0.1);


% NN = struc(1:3,1:3,1:3);

% V = arxstruc(z_train2(1:2760),z_train2(2761:end),NN); 
% order = selstruc(V,0);

% for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% % generar el modelo ARIX con los datos de entrenamiento para cada [na,nb,nk]
% model = arx(z_train,order,'IntegrateNoise',1);
% compare(z_train2,model2) % mostrar un grafico comparativo para los valores
% % reales y modelo ARIX

% n(i,:) % mostrar [na,nb,nk]
% [y_est2,fit2(i)] = compare(z_train2,model2); % encontrar el ajuste (fit) de cada modelo ARIX 

% rmse2(i) = sqrt(mean(y_train2 - y_est2.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

% end
% figure
% plot(t_train2,rmse2);
% title('Error v/s tiempo (entre 30  45 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');

% %% ARMAX 15 a 30 [cm]


% y_train = realSystemOutputFiltered_15_30.output;
% u_train = realSystemOutputFiltered_15_30.input;
% t_train = realSystemOutputFiltered_15_30.time;
% z_train = iddata(y_train,u_train,0.1);

% NN = struc(1:3,1:3,1:3,1:3);

% V = arxstruc(z_train(1:2760),z_train(2761:end),NN);
% order = selstruc(V,0);

% for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% % generar el modelo ARMAX con los datos de entrenamiento para cada [na,nb,nk]
% model = armax(z_train,order);
% compare(z_train,model) % mostrar un grafico comparativo para los valores
% % reales y modelo ARMAX

% n(i,:) % mostrar [na,nb,nk]
% [y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARMAX 

% rmse(i) = sqrt(mean(y_train - y_est.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

% end
% figure
% plot(t_train,rmse);
% title('Error v/s tiempo (entre 15  30 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');

% %% ARMAX 30 a 45 [cm]

% y_train2 = realSystemOutputFiltered_30_45.output;
% u_train2 = realSystemOutputFiltered_30_45.input;
% t_train2 = realSystemOutputFiltered_30_45.time;
% z_train2 = iddata(y_train2,u_train2,0.1);


% NN = struc(1:3,1:3,1:3,1:3);

% V = arxstruc(z_train2(1:2760),z_train2(2761:end),NN);
% order = selstruc(V,0);

% for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% % generar el modelo ARMAX con los datos de entrenamiento para cada [na,nb,nk]
% model = armax(z_train2,order);
% compare(z_train2,model2) % mostrar un grafico comparativo para los valores
% % reales y modelo ARMAX

% n(i,:) % mostrar [na,nb,nk]
% [y_est2,fit2(i)] = compare(z_train2,model2); % encontrar el ajuste (fit) de cada modelo ARMAX

% rmse2(i) = sqrt(mean(y_train2 - y_est2.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

% end
% figure
% plot(t_train2,rmse2);
% title('Error v/s tiempo (entre 30  45 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');


