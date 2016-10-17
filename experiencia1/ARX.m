<<<<<<< HEAD
close all;
clear
clc
load('lastDatos/salidaLazoCerrado3.mat');
load('lastDatos/salidaLazoCerrado2.mat');
=======
getCloseLoopOutputFiltered
close all;

>>>>>>> develop

%Constantes
Ts = 0.01;  %[s]
Fs = 1/Ts; %[Hz]

%%----------------------------------------------------------------------
%%----------------------------------------------------------------------

<<<<<<< HEAD
%Graficos en tiempo y frecuencia de salida (altura) NO Filtrada
signal_15_30 = struct('signal', salidaLazoCerrado3.signals.values(1:5520,2),'time', salidaLazoCerrado3.time(1:5520));
[alturas_f, alturas_S] = Fourier(signal_15_30.signal, Fs);
graficarEnTyF(signal_15_30.time, signal_15_30.signal, alturas_f, alturas_S, 'Close Loop System Out NOT Filtered, 15-30 cm');
%Filtro Pasa Bajos
alturasFiltradas_t = filtroPasaBajos(signal_15_30.signal, Fs, [1], [2]);
%Graficos en tiempo y frecuencia de salida (altura) Filtrada
[alturasFiltradas_f, alturasFiltradas_S] = Fourier(alturasFiltradas_t, Fs);
graficarEnTyF(signal_15_30.time, alturasFiltradas_t, alturasFiltradas_f, alturasFiltradas_S, ' Close Loop System Out Filtered, 15-30 cm');

realSystemOutputFiltered_15_30 = struct('input', salidaLazoCerrado3.signals.values(1:5520,1),'output', alturasFiltradas_t,'time', signal_15_30.time);

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

realSystemOutputFiltered_30_45 = struct('input', salidaLazoCerrado2.signals.values(1150:2730,1),'output', alturasFiltradas_t,'time', signal_30_45.time);


%%----------------------------------------------------------------------
%%----------------------------------------------------------------------

%%Modelos ARX , ARIX  y ARMAX para 2 grupos de entrenamiento
%%Importante: 1) El c�digo no est� probado
=======
%%Modelos ARX , ARIX  y ARMAX para 2 grupos de entrenamiento
%%Importante: 1) El codigo no está probado
>>>>>>> develop
%             2) compare devuelve un tipo, pero deber�a devolver una
%             estructura iddata, por favor verificar esto en la versi�n
%             nueva.

<<<<<<< HEAD
%% ARX 15 a 30 [cm]

y_train = realSystemOutputFiltered_15_30.output;
%u_train = realSystemOutputFiltered_15_30.direct_input;
u_train = realSystemOutputFiltered_15_30.input;
=======
%%----------------------------------------------------------------------
%%---------------------- ARX 15 a 30 [cm]-------------------------------
%%----------------------------------------------------------------------

y_train = realSystemOutputFiltered_15_30.output;
u_train = realSystemOutputFiltered_15_30.direct_input;
%u_train = realSystemOutputFiltered_15_30.input;
>>>>>>> develop
t_train = realSystemOutputFiltered_15_30.time;
z_train = iddata(y_train,u_train,0.1);

n = length(y_train);
NN = struc(1:3,1:3,1:3);

<<<<<<< HEAD
V = arxstruc(z_train(1:(n+1)/2),z_train((n+2)/2+1:end),NN); % entrenamiento y validacion en el mismo conjunto
=======
V = arxstruc(z_train(1:int16((n)/2)),z_train(int16((n+1)/2+1):end),NN); % entrenamiento y validacion en el mismo conjunto
>>>>>>> develop
order = selstruc(V,0);

for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% generar el modelo ARX con los datos de entrenamiento para cada [na,nb,nk]
model = arx(z_train,order);
compare(z_train,model) % mostrar un grafico comparativo para los valores
% reales y modelo ARX

%n(i,:) % mostrar [na,nb,nk]
[y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARX 

%rmse(i) = sqrt(mean(y_train - y_est.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

end
% figure
% plot(t_train,rmse);
% title('Error v/s tiempo (entre 15  30 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');

<<<<<<< HEAD
pause();

%% ARX 30 a 45 [cm]

y_train2 = realSystemOutputFiltered_30_45.output;
%u_train = realSystemOutputFiltered_15_30.direct_input;
u_train2 = realSystemOutputFiltered_30_45.input;
=======
% pause();

%%----------------------------------------------------------------------
%% --------------------------ARX 30 a 45 [cm]---------------------------
%%----------------------------------------------------------------------

y_train2 = realSystemOutputFiltered_30_45.output;
u_train2 = realSystemOutputFiltered_30_45.direct_input;
%u_train2 = realSystemOutputFiltered_30_45.input;
>>>>>>> develop
t_train2 = realSystemOutputFiltered_30_45.time;
z_train2 = iddata(y_train2,u_train2,0.1);

n = length(y_train2);
NN = struc(1:3,1:3,1:3);

<<<<<<< HEAD
V = arxstruc(z_train2(1:(n)/2),z_train2( ((n+1)/2+1):end),NN);
=======
V = arxstruc(z_train2(1:int16((n)/2)),z_train2( int16((n+1)/2+1):end),NN);
>>>>>>> develop
order = selstruc(V,0);

for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% generar el modelo ARX con los datos de entrenamiento para cada [na,nb,nk]
model2 = arx(z_train2,order);
compare(z_train2,model2) % mostrar un grafico comparativo para los valores
% reales y modelo ARX

%n(i,:) % mostrar [na,nb,nk]
[y_est2,fit2(i)] = compare(z_train2,model2); % encontrar el ajuste (fit) de cada modelo ARX 

%rmse2(i) = sqrt(mean(y_train2 - y_est2.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

end
% figure
% plot(t_train2,rmse2);
% title('Error v/s tiempo (entre 30  45 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');
pause();

<<<<<<< HEAD
=======
%%----------------------------------------------------------------------
%% ------------------------ARX 45 a 60 [cm]-----------------------------
%%----------------------------------------------------------------------

y_train = realSystemOutputFiltered_45_60.output;
u_train = realSystemOutputFiltered_45_60.direct_input;
%u_train = realSystemOutputFiltered_45_60.input;
t_train = realSystemOutputFiltered_45_60.time;
z_train = iddata(y_train,u_train,0.1);

n = length(y_train);
NN = struc(1:3,1:3,1:3);

V = arxstruc(z_train(1:int16((n)/2)),z_train(int16((n+1)/2+1):end),NN); % entrenamiento y validacion en el mismo conjunto
order = selstruc(V,0);

for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% generar el modelo ARX con los datos de entrenamiento para cada [na,nb,nk]
model = arx(z_train,order);
compare(z_train,model) % mostrar un grafico comparativo para los valores
% reales y modelo ARX

%n(i,:) % mostrar [na,nb,nk]
[y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARX 

%rmse(i) = sqrt(mean(y_train - y_est.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

end
% figure
% plot(t_train,rmse);
% title('Error v/s tiempo (entre 45  60 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');

% pause();

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%% ARIX %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

>>>>>>> develop
%% ARIX 15 a 30 [cm]


y_train = realSystemOutputFiltered_15_30.output;
<<<<<<< HEAD
%u_train = realSystemOutputFiltered_15_30.direct_input;
u_train = realSystemOutputFiltered_15_30.input;
=======
u_train = realSystemOutputFiltered_15_30.direct_input;
%u_train = realSystemOutputFiltered_15_30.input;
>>>>>>> develop
t_train = realSystemOutputFiltered_15_30.time;
z_train = iddata(y_train,u_train,0.1);

NN = struc(1:3,1:3,1:3);

n = length(y_train);
<<<<<<< HEAD
V = arxstruc(z_train(1:(n+1)/2),z_train((n+2)/2+1:end),NN);
=======
V = arxstruc(z_train(1:int16((n)/2)),z_train((n+1)/2+1:end),NN);
>>>>>>> develop
order = selstruc(V,0);

for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% generar el modelo ARIX con los datos de entrenamiento para cada [na,nb,nk]

model = arx(z_train,order,'IntegrateNoise',1); %%NO CORRE EN 2009
%model = arx(z_train,order);
compare(z_train,model) % mostrar un grafico comparativo para los valores
% reales y modelo ARIX

%n(i,:) % mostrar [na,nb,nk]
<<<<<<< HEAD
[y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARIX 
=======
[y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARIX
>>>>>>> develop

%rmse(i) = sqrt(mean(y_train - y_est.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

end
% figure
% plot(t_train,rmse);
% title('Error v/s tiempo (entre 15  30 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');

<<<<<<< HEAD
pause();
=======
% pause();
>>>>>>> develop

%% ARXIX 30 a 45 [cm]

y_train2 = realSystemOutputFiltered_30_45.output;
<<<<<<< HEAD
%u_train = realSystemOutputFiltered_15_30.direct_input;
u_train2 = realSystemOutputFiltered_30_45.input;
=======
u_train = realSystemOutputFiltered_30_45.direct_input;
%u_train2 = realSystemOutputFiltered_30_45.input;
>>>>>>> develop
t_train2 = realSystemOutputFiltered_30_45.time;
z_train2 = iddata(y_train2,u_train2,0.1);

n = length(y_train2);
NN = struc(1:3,1:3,1:3);

<<<<<<< HEAD
V = arxstruc(z_train2(1:(n)/2),z_train2((n+1)/2+1:end),NN); 
=======
V = arxstruc(z_train2(1:int16((n)/2)),z_train2(int16((n+1)/2+1):end),NN); 
>>>>>>> develop
order = selstruc(V,0);

for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% generar el modelo ARIX con los datos de entrenamiento para cada [na,nb,nk]

model2 = arx(z_train,order,'IntegrateNoise',1); %NO CORRE EN 2009
%model2 = arx(z_train,order);
compare(z_train2,model2) % mostrar un grafico comparativo para los valores
% reales y modelo ARIX

%n(i,:) % mostrar [na,nb,nk]
[y_est2,fit2(i)] = compare(z_train2,model2); % encontrar el ajuste (fit) de cada modelo ARIX 

%rmse2(i) = sqrt(mean(y_train2 - y_est2.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

end
% figure
% plot(t_train2,rmse2);
% title('Error v/s tiempo (entre 30  45 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');

pause();

<<<<<<< HEAD
%% ARMAX 15 a 30 [cm]


y_train = realSystemOutputFiltered_15_30.output;
%u_train = realSystemOutputFiltered_15_30.direct_input;
u_train = realSystemOutputFiltered_15_30.input;
t_train = realSystemOutputFiltered_15_30.time;
z_train = iddata(y_train,u_train,0.1);

n = length(y_train);
%NN = struc(1:3,1:3,1:3,1:3);
NN = struc(1:3,1:3,1:3,1:3);

%V = arxstruc(z_train(1:(n+1)/2),z_train((n+2)/2+1:end),NN);
%order = selstruc(V,0);

for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% generar el modelo ARMAX con los datos de entrenamiento para cada [na,nb,nk]

z_ent = z_train(1:(n+1)/2);
model = armax(z_ent,NN);
compare(z_train,model) % mostrar un grafico comparativo para los valores
% reales y modelo ARMAX

%n(i,:) % mostrar [na,nb,nk]
[y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARMAX 

%no corre en 2009
=======
% ARIX 45 a 60 [cm]


y_train = realSystemOutputFiltered_45_60.output;
u_train = realSystemOutputFiltered_45_60.direct_input;
%u_train = realSystemOutputFiltered_45_60.input;
t_train = realSystemOutputFiltered_45_60.time;
z_train = iddata(y_train,u_train,0.1);

NN = struc(1:3,1:3,1:3);

n = length(y_train);
V = arxstruc(z_train(1:int16((n+1)/2)),z_train(int16((n+2)/2+1):end),NN);
order = selstruc(V,0);

for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% generar el modelo ARIX con los datos de entrenamiento para cada [na,nb,nk]

model = arx(z_train,order,'IntegrateNoise',1); %%NO CORRE EN 2009
%model = arx(z_train,order);
compare(z_train,model) % mostrar un grafico comparativo para los valores
% reales y modelo ARIX

%n(i,:) % mostrar [na,nb,nk]
[y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARIX 

>>>>>>> develop
%rmse(i) = sqrt(mean(y_train - y_est.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

end
% figure
% plot(t_train,rmse);
% title('Error v/s tiempo (entre 15  30 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');

<<<<<<< HEAD
pause();
%% ARMAX 30 a 45 [cm]

y_train2 = realSystemOutputFiltered_30_45.output;
%u_train = realSystemOutputFiltered_15_30.direct_input;
u_train2 = realSystemOutputFiltered_30_45.input;
t_train2 = realSystemOutputFiltered_30_45.time;
z_train2 = iddata(y_train2,u_train2,0.1);

n = length(y_train2);
NN = struc(1:3,1:3,1:3,1:3);

%V = arxstruc(z_train2(1:n),z_train2(n+1:end),NN);
%order = selstruc(V,0);

for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% generar el modelo ARMAX con los datos de entrenamiento para cada [na,nb,nk]
z_ent2 = z_train2(1:(n+1)/2);
model2 = armax(z_ent2,NN);
compare(z_train2,model2) % mostrar un grafico comparativo para los valores
% reales y modelo ARMAX

[y_est2,fit2(i)] = compare(z_train2,model2); % encontrar el ajuste (fit) de cada modelo ARMAX

%rmse2(i) = sqrt(mean(y_train2 - y_est2.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

end
% figure
% plot(t_train2,rmse2);
% title('Error v/s tiempo (entre 30  45 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');
% 

=======
% pause();

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%ARMAX%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% ARMAX 15 a 30 [cm]


% y_train = realSystemOutputFiltered_15_30.output;
% u_train = realSystemOutputFiltered_15_30.direct_input;
% %u_train = realSystemOutputFiltered_15_30.input;
% t_train = realSystemOutputFiltered_15_30.time;
% z_train = iddata(y_train,u_train,0.1);

% n = length(y_train);
% %NN = struc(1:3,1:3,1:3,1:3);
% NN = struc(1:3,1:3,1:3,1:3);

% V = arxstruc(z_train(1:int16((n)/2)),z_train(int16((n+1)/2+1):end),NN);
% order = selstruc(V,0);

% for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% % generar el modelo ARMAX con los datos de entrenamiento para cada [na,nb,nk]

% % z_ent = z_train(1:(n+1)/2);
% model = armax(z_ent,order);
% compare(z_train,model) % mostrar un grafico comparativo para los valores
% % reales y modelo ARMAX

% %n(i,:) % mostrar [na,nb,nk]
% [y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARMAX 

% %no corre en 2009
% %rmse(i) = sqrt(mean(y_train - y_est.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

% end
% % figure
% % plot(t_train,rmse);
% % title('Error v/s tiempo (entre 30  45 [cm])')
% % xlabel('tiempo [s]');
% % ylabel('altura [cm]');

% % pause();
% %% ARMAX 30 a 45 [cm]

% y_train2 = realSystemOutputFiltered_30_45.output;
% u_train = realSystemOutputFiltered_30_45.direct_input;
% %u_train2 = realSystemOutputFiltered_30_45.input;
% t_train2 = realSystemOutputFiltered_30_45.time;
% z_train2 = iddata(y_train2,u_train2,0.1);

% n = length(y_train2);
% NN = struc(1:3,1:3,1:3,1:3);

% %V = arxstruc(z_train2(1:n),z_train2(n+1:end),NN);
% %order = selstruc(V,0);

% for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% % generar el modelo ARMAX con los datos de entrenamiento para cada [na,nb,nk]
% z_ent2 = z_train2(1:(n+1)/2);
% model2 = armax(z_ent2,NN);
% compare(z_train2,model2) % mostrar un grafico comparativo para los valores
% % reales y modelo ARMAX

% [y_est2,fit2(i)] = compare(z_train2,model2); % encontrar el ajuste (fit) de cada modelo ARMAX

% %rmse2(i) = sqrt(mean(y_train2 - y_est2.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

% end
% % figure
% % plot(t_train2,rmse2);
% % title('Error v/s tiempo (entre 30  45 [cm])')
% % xlabel('tiempo [s]');
% % ylabel('altura [cm]');
% % 

% %% ARMAX 45 a 60 [cm]


% y_train = realSystemOutputFiltered_45_60.output;
% %u_train = realSystemOutputFiltered_45_60.direct_input;
% u_train = realSystemOutputFiltered_45_60.input;
% t_train = realSystemOutputFiltered_45_60.time;
% z_train = iddata(y_train,u_train,0.1);

% n = length(y_train);
% %NN = struc(1:3,1:3,1:3,1:3);
% NN = struc(1:3,1:3,1:3,1:3);

% %V = arxstruc(z_train(1:(n+1)/2),z_train((n+2)/2+1:end),NN);
% %order = selstruc(V,0);

% for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% % generar el modelo ARMAX con los datos de entrenamiento para cada [na,nb,nk]

% z_ent = z_train(1:(n+1)/2);
% model = armax(z_ent,NN);
% compare(z_train,model) % mostrar un grafico comparativo para los valores
% % reales y modelo ARMAX

% %n(i,:) % mostrar [na,nb,nk]
% [y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARMAX 

% %no corre en 2009
% %rmse(i) = sqrt(mean(y_train - y_est.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

% end
% % figure
% % plot(t_train,rmse);
% % title('Error v/s tiempo (entre 45  60 [cm])')
% % xlabel('tiempo [s]');
% % ylabel('altura [cm]');

% % pause();
>>>>>>> develop
