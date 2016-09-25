%%Parametros del modelo fenomenologico, segun regresion lineal
%Datos experimento 1. Valvula de salida cerrada
getParametros
Fin = FlujosProm';
Frec = frecuencias;
params = linearRegression(Fin, Frec);
c1 = params(2)
c2 = params(1)

%Datos experimento 2. Valvula de entrada cerrad

% getParametrosBeta

% for i=1:length(frecuencias)
%     i_filt = strcat('filt',int2str(i));
%     i_volumen = strcat('v',int2str(i));
    
%     Fout = volumenesFiltrados.(i_volumen);
%     sqrt_h = sqrt(h_datas_filtradas.(i_filt));

%     leftLimit = 20;
%     rightLimit = 20;
%     FoutValid = Fout(leftLimit:length(Fout)-rightLimit);
%     sqrt_hValid = sqrt_h(leftLimit:length(sqrt_h)-rightLimit);

% 	params2 = linearRegression(FoutValid', sqrt_hValid');
% 	betas(i) = params2(2);
% 	betaOfsets(i) = params2(1);
% end

% betaProm = mean(betas)
% betaOfset = mean(betaOfsets)