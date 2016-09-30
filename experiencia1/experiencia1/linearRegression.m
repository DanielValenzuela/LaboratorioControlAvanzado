function [ params ] = linearRegression( y, x )
    format long
    figure('Name','Regresión Lineal','NumberTitle','off');
    hold on
    plot(x,y,'bo-')
    xlabel('Frecuencia de la bomba')
    ylabel('Flujo Promedio')
    title('Modelo mediante Regresion Lineal')
    grid on
    X = [ones(length(x),1) x];
    params = X\y;
    b0 = params(1); %intersect
    b1 = params(2); %slope
    yCalc = X*params;
    plot(x,yCalc,'r--')
    legend('Data','Slope & Intercept','Location','best');
end