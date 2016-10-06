getCloseLoopOutputFiltered
close all;


%Constantes
Ts = 0.01;  %[s]
Fs = 1/Ts; %[Hz]

%%----------------------------------------------------------------------
%%----------------------------------------------------------------------

%%Modelos ARX , ARIX  y ARMAX para 2 grupos de entrenamiento
%%Importante: 1) El c�digo no est� probado
%             2) compare devuelve un tipo, pero deber�a devolver una
%             estructura iddata, por favor verificar esto en la versi�n
%             nueva.

%% ARX 15 a 30 [cm]

y_train = realSystemOutputFiltered_15_30.output;
u_train = realSystemOutputFiltered_15_30.direct_input;
%u_train = realSystemOutputFiltered_15_30.input;
t_train = realSystemOutputFiltered_15_30.time;
z_train = iddata(y_train,u_train,0.1);

n = length(y_train);
NN = struc(1:3,1:3,1:3);

V = arxstruc(z_train(1:(n)/2),z_train((n+1)/2+1:end),NN); % entrenamiento y validacion en el mismo conjunto
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

pause();

%% ARX 30 a 45 [cm]

y_train2 = realSystemOutputFiltered_30_45.output;
u_train = realSystemOutputFiltered_15_30.direct_input;
%u_train2 = realSystemOutputFiltered_30_45.input;
t_train2 = realSystemOutputFiltered_30_45.time;
z_train2 = iddata(y_train2,u_train2,0.1);

n = length(y_train2);
NN = struc(1:3,1:3,1:3);

V = arxstruc(z_train2(1:(n)/2),z_train2( ((n+1)/2+1):end),NN);
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

%% ARX 45 a 60 [cm]

% y_train = realSystemOutputFiltered_45_60.output;
% u_train = realSystemOutputFiltered_45_60.direct_input;
% %u_train = realSystemOutputFiltered_45_60.input;
% t_train = realSystemOutputFiltered_45_60.time;
% z_train = iddata(y_train,u_train,0.1);

% n = length(y_train);
% NN = struc(1:3,1:3,1:3);

% V = arxstruc(z_train(1:(n)/2),z_train((n+1)/2+1:end),NN); % entrenamiento y validacion en el mismo conjunto
% order = selstruc(V,0);

% for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% % generar el modelo ARX con los datos de entrenamiento para cada [na,nb,nk]
% model = arx(z_train,order);
% compare(z_train,model) % mostrar un grafico comparativo para los valores
% % reales y modelo ARX

% %n(i,:) % mostrar [na,nb,nk]
% [y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARX 

% %rmse(i) = sqrt(mean(y_train - y_est.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

% end
% % figure
% % plot(t_train,rmse);
% % title('Error v/s tiempo (entre 45  60 [cm])')
% % xlabel('tiempo [s]');
% % ylabel('altura [cm]');

% pause();

%%%%%%%%%%%%%%%%%%%%%%%%%%%% ARIX %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% ARIX 15 a 30 [cm]


y_train = realSystemOutputFiltered_15_30.output;
u_train = realSystemOutputFiltered_15_30.direct_input;
%u_train = realSystemOutputFiltered_15_30.input;
t_train = realSystemOutputFiltered_15_30.time;
z_train = iddata(y_train,u_train,0.1);

NN = struc(1:3,1:3,1:3);

n = length(y_train);
V = arxstruc(z_train(1:(n+1)/2),z_train((n+2)/2+1:end),NN);
order = selstruc(V,0);

for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% generar el modelo ARIX con los datos de entrenamiento para cada [na,nb,nk]

model = arx(z_train,order,'IntegrateNoise',1); %%NO CORRE EN 2009
%model = arx(z_train,order);
compare(z_train,model) % mostrar un grafico comparativo para los valores
% reales y modelo ARIX

%n(i,:) % mostrar [na,nb,nk]
[y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARIX 

%rmse(i) = sqrt(mean(y_train - y_est.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

end
% figure
% plot(t_train,rmse);
% title('Error v/s tiempo (entre 15  30 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');

pause();

%% ARXIX 30 a 45 [cm]

y_train2 = realSystemOutputFiltered_30_45.output;
u_train = realSystemOutputFiltered_15_30.direct_input;
%u_train2 = realSystemOutputFiltered_30_45.input;
t_train2 = realSystemOutputFiltered_30_45.time;
z_train2 = iddata(y_train2,u_train2,0.1);

n = length(y_train2);
NN = struc(1:3,1:3,1:3);

V = arxstruc(z_train2(1:(n)/2),z_train2((n+1)/2+1:end),NN); 
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

%% ARIX 45 a 60 [cm]


% y_train = realSystemOutputFiltered_45_60.output;
% u_train = realSystemOutputFiltered_45_60.direct_input;
% %u_train = realSystemOutputFiltered_45_60.input;
% t_train = realSystemOutputFiltered_45_60.time;
% z_train = iddata(y_train,u_train,0.1);

% NN = struc(1:3,1:3,1:3);

% n = length(y_train);
% V = arxstruc(z_train(1:(n+1)/2),z_train((n+2)/2+1:end),NN);
% order = selstruc(V,0);

% for i = 1:18 % i = 1:hasta todas las combinaciones posibles de valores struc

% % generar el modelo ARIX con los datos de entrenamiento para cada [na,nb,nk]

% model = arx(z_train,order,'IntegrateNoise',1); %%NO CORRE EN 2009
% %model = arx(z_train,order);
% compare(z_train,model) % mostrar un grafico comparativo para los valores
% % reales y modelo ARIX

% %n(i,:) % mostrar [na,nb,nk]
% [y_est,fit(i)] = compare(z_train,model); % encontrar el ajuste (fit) de cada modelo ARIX 

% %rmse(i) = sqrt(mean(y_train - y_est.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

% end
% % figure
% % plot(t_train,rmse);
% % title('Error v/s tiempo (entre 15  30 [cm])')
% % xlabel('tiempo [s]');
% % ylabel('altura [cm]');

% pause();

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%ARMAX%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
%rmse(i) = sqrt(mean(y_train - y_est.y).^2); % RMSE, para indicar el error cuadratico medio de cada modelo

end
% figure
% plot(t_train,rmse);
% title('Error v/s tiempo (entre 30  45 [cm])')
% xlabel('tiempo [s]');
% ylabel('altura [cm]');

pause();
%% ARMAX 30 a 45 [cm]

y_train2 = realSystemOutputFiltered_30_45.output;
u_train = realSystemOutputFiltered_15_30.direct_input;
%u_train2 = realSystemOutputFiltered_30_45.input;
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

%% ARMAX 45 a 60 [cm]


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

% pause();