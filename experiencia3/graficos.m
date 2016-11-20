%% CODIGO INFORME 3 (E INFORME 4!)
clear all

%% GRAFICOS ESPECIFICOS, loadData con la segunda opcion en 0, solo carga los datos del archivo
%% "filename", con el valor DISTINTO de 0 grafica pero genericamente

%PONGO TODOS ESTOS COMENTES PARA EJEMPLIFICAR, si quieres los borras

% fileName ='DATOS_ADAPTIVO1';
% loadData('DATOS_ADAPTIVO1',0);
% 
% %%GRAFICOS PARA DATOS_ADAPTIVO1
% graphInTime(errPlanta.time, errPlanta.signals.values, 'Error de la planta' , [0 160], 'b',1, 'b');
% 
% graphInTime(alphaHorizontal.time, alphaHorizontal.signals.values, 'Ángulo horizontal twin rotor' , [0 160], 'b',1, 'b');
% graphInTime(alphaVertical.time, alphaVertical.signals.values, 'Ángulo vertical twin rotor' , [0 160], 'b',1, 'b');
% graphInTime(errHorizontal.time, errHorizontal.signals.values, 'Error ángulo horizontal' , [0 160], 'b',1, 'b');
% graphInTime(errVertical.time, alphaVertical.signals.values, 'Ángulo vertical twin rotor' , [0 160], 'b',1, 'b');
% 
% 
% graphInTime(errVadaptivo.time, errVadaptivo.signals.values, 'Error adaptativo ángulo vertical' , [0 160], 'b',1, 'b');
% graphInTime(errVadaptivo1.time, errVadaptivo1.signals.values, 'Error adaptativo1 ángulo vertical' , [0 160], 'b',1, 'b');
% 
% graphInTime(inHorizontal.time, inHorizontal.signals.values, 'Entrada ángulo horizontal twin rotor' , [0 160], 'b',1, 'b');
% graphInTime(inHorizontal1.time, inHorizontal1.signals.values, 'Entrada ángulo horizontal1 twin rotor' , [0 160], 'b',1, 'b');
% graphInTime(inHorizontal2.time, inHorizontal2.signals.values, 'Entrada ángulo horizontal2 twin rotor' , [0 160], 'b',1, 'b');
% graphInTime(inVertical.time, inVertical.signals.values, 'Entrada ángulo vertical twin rotor' , [0 160], 'b',1, 'b');



%PARA GRAFICOS PARA GRAFICOS GENERALES (descomentar este y comentar codigo de arriba)

loadData('DATOS_ADAPTIVO1',1);

