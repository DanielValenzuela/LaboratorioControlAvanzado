function y = IAE(params)
    parameters;
    %Kp = params(1);
    %Ki = params(2);
    %Lambda = params(4);
    %Kd = params(3);
    %Mu = params(5);
    % Cargando parametros
    if ControllerType == 0
        %-------------------- Funcion Objetivo PIDOF --------------------
        assignin('base','ctrl',2);
        assignin('base','Kp',params(1));
        assignin('base','Ki',params(2));
        assignin('base','lambda',params(3));
        assignin('base','Kd',params(4));
        assignin('base','mu',params(5));
    elseif ControllerType == 1  %PID
        %-------------------- Funcion Objetivo PID --------------------
        assignin('base','ctrl',1);
        assignin('base','Kp',params(1));
        assignin('base','Ki',params(2));
        assignin('base','Kd',params(3));
        assignin('base','lambda',1);
        assignin('base','mu',1);
    elseif ControllerType == 2
        %-------------------- Funcion Objetivo PIOF --------------------
        assignin('base','ctrl',4);
        assignin('base','Kp',params(1));
        assignin('base','Ki',params(2));
        assignin('base','lambda',params(3));
        assignin('base','Kd',0);
        assignin('base','mu',1);
    else
        %-------------------- Funcion Objetivo PI --------------------
        assignin('base','ctrl',3);
        assignin('base','Kp',params(1));
        assignin('base','Ki',params(2));
        assignin('base','lambda',1);
        assignin('base','Kd',0);
        assignin('base','mu',1);
    end

    % Corriendo simulacion
    sim('IV_actividad2');
    % Obteniendo arreglo error
    e = error.signals.values;
    absE = zeros(size(e));
    for i=1:length(e)
        absE(i) = abs(e(i));
    end
    %obteniendo IAE
    y = integral(absE,0.1);
    y = y'*y;
end