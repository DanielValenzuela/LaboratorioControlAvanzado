function showResults(params)
	parameters;

	%Constraints tolerances
	e1 = 70;
	e2 = 1;
	e3 = 15;
	e4 = 25;

	fprintf('Parametros de los controladores:\n\n');

	if ControllerType == 0
		%-------------------- Valor Funcion Objetivo PIDOF --------------------
		fun  = objectiveFunc(params);
		C_jwcg = controllerTransferFcn(params, wcg, 'paralela');
		C_jwh = controllerTransferFcn(params, wh, 'paralela');
		C_jwl = controllerTransferFcn(params, wl, 'paralela');
		strType = 'PIDOF';
		% Mostrar valores por consola
		fprintf( 'Tipo  | Kp          | Ki         | lambda    | Kd         | mu        |\n');
		fprintf('________________________________________________________________________________\n');
		fprintf( '%s | %4.4f     |%4.4f     |%4.4f     |%4.4f     |%4.4f     |\n', strType, params(1), params(2), params(3), params(4), params(5));
		% Guardar datos a archivo de texto
		fileID = fopen(strcat('results',strType,'.txt'),'w');
		fprintf(fileID, 'Parametros de los controladores:\n\n');
		fprintf(fileID, 'Tipo  | Kp           | Ki           | lambda      | Kd           | mu        |\n');
		fprintf(fileID, '________________________________________________________________________________\n');
		fprintf(fileID, '%s | %4.4f     |%4.4f     |%4.4f     |%4.4f     |%4.4f     |\n', strType, params(1), params(2), params(3), params(4), params(5));
	elseif ControllerType == 1	%PID
		%-------------------- Valor Funcion Objetivo PID --------------------
		fun  = objectiveFuncPID(params);
		C_jwcg = controllerTransferFcnPID(params, wcg, 'paralela');
		C_jwh = controllerTransferFcnPID(params, wh, 'paralela');
		C_jwl = controllerTransferFcnPID(params, wl, 'paralela');
		strType = 'PID  ';
		% Mostrar valores por consola
		fprintf( 'Tipo  | Kp          | Ki          | Kd         |\n');
		fprintf('________________________________________________________________________________\n');
		fprintf( '%s | %4.4f     |%4.4f     |%4.4f     |\n', strType, params(1), params(2), params(3));
		% Guardar datos a archivo de texto
		fileID = fopen(strcat('results',strType,'.txt'),'w');
		fprintf(fileID, 'Parametros de los controladores:\n\n');
		fprintf(fileID, 'Tipo  | Kp           | Ki            | Kd            |\n');
		fprintf(fileID, '________________________________________________________________________________\n');
		fprintf(fileID, '%s | %4.4f     |%4.4f     |%4.4f     |\n', strType, params(1), params(2), params(3));
	elseif ControllerType == 2
		%-------------------- Valor Funcion Objetivo PIOF --------------------
		fun  = objectiveFuncPIOF(params);
		C_jwcg = controllerTransferFcnPIOF(params, wcg, 'paralela');
		C_jwh = controllerTransferFcnPIOF(params, wh, 'paralela');
		C_jwl = controllerTransferFcnPIOF(params, wl, 'paralela');
		strType = 'PIOF ';
		% Mostrar valores por consola
		fprintf( 'Tipo  | Kp          | Ki         | lambda    |\n');
		fprintf('________________________________________________________________________________\n');
		fprintf( '%s | %4.4f     |%4.4f    |%4.4f     |\n', strType, params(1), params(2), params(3));
		% Guardar datos a archivo de texto
		fileID = fopen(strcat('results',strType,'.txt'),'w');
		fprintf(fileID, 'Parametros de los controladores:\n\n');
		fprintf(fileID, 'Tipo  | Kp          | Ki         | lambda   |\n');
		fprintf(fileID, '________________________________________________________________________________\n');
		fprintf(fileID, '%s | %4.4f     |%4.4f    |%4.4f     |\n', strType, params(1), params(2), params(3));
	else
		%-------------------- Valor Funcion Objetivo PI --------------------
		fun  = objectiveFuncPI(params);
		C_jwcg = controllerTransferFcnPI(params, wcg, 'paralela');
		C_jwh = controllerTransferFcnPI(params, wh, 'paralela');
		C_jwl = controllerTransferFcnPI(params, wl, 'paralela');
		strType = 'PI   ';
		% Mostrar valores por consola
		fprintf( 'Tipo  | Kp          | Ki          |\n');
		fprintf('________________________________________________________________________________\n');
		fprintf( '%s | %4.4f     |%4.4f     |\n', strType, params(1), params(2));
		% Guardar datos a archivo de texto
		fileID = fopen(strcat('results',strType,'.txt'),'w');
		fprintf(fileID, 'Parametros de los controladores:\n\n');
		fprintf(fileID, 'Tipo  | Kp         | Ki        |\n');
		fprintf(fileID, '________________________________________________________________________________\n');
		fprintf(fileID, '%s | %4.4f     |%4.4f     |\n', strType, params(1), params(2));
	end

    %System Transfers functions
	G_jwcg = numG/(1j*wcg-poloG);
	G_jwh = numG/(1j*wh-poloG);
	G_jwl = numG/(1j*wl-poloG);

	r1 = abs(angle(C_jwcg*G_jwcg)+pi-phi_m)-e1;
	r2 = abs(restriction2(params))-e2;
	r3 = abs((C_jwh*G_jwh)/(1+C_jwh*G_jwh))-H-e3;
	r4 = abs(1/(1+C_jwl*G_jwl))-N-e4;

	% Mostrar valores por consola
	fprintf('\n\n\nParametros del problema de optimizacion:\n\n');
	fprintf('Tipo  | Func. Obj.   | r1           | r2           | r3           | r4         |\n');
	fprintf('________________________________________________________________________________\n');
	% fprintf('----------------------------------------------------------------------------------\n');
	            fprintf( '%s | %d |%4.4f       |%4.4f       |%4.4f       |%4.4f     |\n', strType, fun, r1, r2, r3, r4);
	
	% Guardar datos a archivo de texto
	fprintf(fileID, '\n\n\nParametros del problema de optimizacion:\n\n');
	fprintf(fileID, 'Tipo  | Func. Obj.   | r1           | r2           | r3           | r4         |\n');
	fprintf(fileID, '________________________________________________________________________________\n');
	% fprintf(fileID, '----------------------------------------------------------------------------------\n');
	             fprintf(fileID, '%s | %d |%4.4f       |%4.4f       |%4.4f       |%4.4f     |\n', strType, fun, r1, r2, r3, r4);
	fclose(fileID);
end