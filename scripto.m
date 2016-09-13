%Elección de entrada y salida para entrenamiento
u=randn([1 2000])*0.4;
u(1800:end) = 1.8*sin(linspace(1,30,201));
y = salida(u);
u = u';
y=y';

%% Conjuntos de Entrenamiento, Validación y Prueba
ytrain=y(1:1000);
yvalid=y(1001:1500);
ytest=y(1501:2000);
utrain=u(1:1000,1);
uvalid=u(1001:1500,1);
utest=u(1501:2000,1);

% Grafico Entrada
figure,
hold on;

plot(1:1000,u(1:1000));
plot(1001:1500,u(1001:1500),'r');
plot(1501:2000,u(1501:2000),'g');
ylabel('Entrada U(k)');
xlabel('Instante k');
title('Conjunto Entrada/Salida');

% Grafico Salida
figure,
hold on;
plot(1:1000,y(1:1000));
plot(1001:1500,y(1001:1500),'r');
plot(1501:2000,y(1501:2000),'g');
legend('Entrenamiento','Validación','Prueba');
ylabel('Salida Y(k)');
xlabel('Instante k');
title('Salida de la planta no lineal');


%modelo para entrenamiento
TRAIN=iddata(ytrain,utrain,1);

FPE=zeros(25,25);
for i=1:25
    for j=1:25
        mod1 = arx(TRAIN,[i j,0]); 
        FPE1(i,j)=mod1.EstimationInfo.FPE;
    end
end

[IndiceAR,Indiceu]=find(FPE1==min(min(FPE1)));
mod=arx(TRAIN,[IndiceAR, Indiceu,0]);

%Graficos, 1 paso
E1=sim(mod,utrain);
figure,
hold on
plot(1:1000,ytrain);
plot(1:1000,E1,'g');
ylabel('Salida Y(k)');
xlabel('Instante k');
title(strcat('Meor ARX vs. Train a 1 Paso'));
legend('Conjunto Entrenamiento','Modelo ARX');

V1=predict(mod,[yvalid,uvalid],1);
figure,
hold on
plot(1:500,yvalid);
plot(1:500,V1{1,1},'g')
ylabel('Salida Y(k)');
xlabel('Instante k');
title(strcat('Mejor ARX vs. Validation a 1 Paso '));
legend('Conjunto Validación','Modelo ARX');

T1=predict(mod,[ytest,utest],1); 
figure,
hold on
plot(1:500,ytest);
plot(1:500,T1{1,1},'g');
ylabel('Salida Y(k)');
xlabel('Instante k');
title(strcat('Mejor ARX vs. Test a 1 Paso'));
legend('Conjunto Prueba','Modelo ARX');
figure,

%Graficos, 10 pasos
FPE10=zeros(25,25);

for i=1:25
    for j=1:25
        mod1 = arx(TRAIN,[i j,0]); 
        FPE10(i,j)=mod1.EstimationInfo.FPE;
    end
end

[IndiceAR10,Indiceu10]=find(FPE10==min(min(FPE10)));
mod=ARX(TRAIN,[IndiceAR10, Indiceu10,0]);

E10=sim(mod,utrain);
figure,
hold on
plot(1:1000,ytrain);
plot(1:1000,E10,'g');
ylabel('Salida Y(k)');
xlabel('Instante k');
title(strcat('Mejor ARX vs. Train a 10 Pasos'));
legend('Conjunto Entrenamiento','Modelo ARX');

V10=predict(mod,[yvalid,uvalid],10);
figure,
hold on
plot(1:500,yvalid);
plot(1:500,V10{1,1},'g')
ylabel('Salida Y(k)');
xlabel('Instante k');
title(strcat('Mejor ARX vs. Validation a 10 Pasos'));
legend('Conjunto Validación','Modelo ARX');

T10=predict(mod,[ytest,utest],10); 
figure,
hold on
plot(1:500,ytest);
plot(1:500,T10{1,1},'g');
ylabel('Salida Y(k)');
xlabel('Instante k');
title(strcat('Mejor ARX vs. Test a 10 Pasos'));
legend('Conjunto Prueba','Modelo ARX');