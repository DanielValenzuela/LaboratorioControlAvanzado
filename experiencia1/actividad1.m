%%Parametros del modelo fenomenologico, segun regresion lineal
%Datos experimento 1. Valvula de salida cerrada
Fin = [];
Frec = [];
params = linear_regression(Fin, Frec);
c1 = params(2)
c2 = params(1)
%Datos experimento 2. Valvula de entrada cerrada
Fout = [];
beta = sqrt(h)\Fout