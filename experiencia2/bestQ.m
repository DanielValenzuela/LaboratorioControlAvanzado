minMetrica = 100000;
L = [1920 720 70 4920];
N = [2080 880 230 5080];
step_ = 40;
best_params = [];
bestMins = struct('min0',[],'min1',[],'min2',[],'min3',[],'min4',[],'min5',[]);
count = 0;

for x1=L(1):step_:N(1)
	for x2=L(2):step_:N(2)
		for x3=L(3):step_:N(3)
			for x4=L(4):step_:N(4)
				Q_i = [x1 0 0 0; 0 x2 0 0; 0 0 x3 0; 0 0 0 x4];
				K = setK_lqr(Q_i);
				sim('nonlinearEcuaciones');
				Mp = max(theta.signals.values(:,1));
				tsIndex = findTs(theta.signals.values);
				ts = theta.time(tsIndex);
				actualMetrica = metricaMpTs(Mp, ts);
				% if (mod(x4,5)==0)
				% 	display('JUST UPDATE');
				% 	x4
			 % 		Mp
			 % 		ts
			 % 		minMetrica
			 % 		best_params
				% end
				inLimits = boolInLimit(position.signals.values);
				if (actualMetrica<minMetrica && inLimits)
					% display('MIN FOUND found');
					minMetrica = actualMetrica;
					Mp
					ts
					best_params = [x1, x2, x3, x4]
					i = strcat('min',int2str(count));
					bestMins.(i) = best_params;
					count = mod(count+1, 6);
				end
			end
		end
	end
end


% for xi=1:N(4)
% 	Q_i = [1 0 0 0; 0 478 0 0; 0 0 xi 0; 0 0 0 7];
% 	K = setK_lqr(Q_i);
% 	sim('nonlinearEcuaciones');
% 	Mp = max(theta.signals.values(:,1));
% 	tsIndex = findTs(theta.signals.values);
% 	ts = theta.time(tsIndex);
% 	actualMetrica = metricaMpTs(Mp, ts);
% 	if (mod(xi,20)==0)
% 		xi
% 		Mp
% 		ts
% 		minMetrica
% 	end
% 	if actualMetrica<minMetrica
% 		minMetrica = actualMetrica;
% 		best_params = [1, xi, 10, 7];
% 	end
% end

best_params
minMetrica
Mp
ts