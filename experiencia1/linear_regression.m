function [ params ] = linear_regression( y, x )
    format long
    scatter(x,y)
    hold on
    xlabel('Frecuencia de la bomba')
    ylabel('Flujo de entrada (valvula de salida cerrada)')
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

