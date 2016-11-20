close all
%Real vs simulation Graphs
Q_optimo = [20 0 0 0; 0 30 0 0; 0 0 30 0; 0 0 0 30];
K = setK_lqr(Q_optimo);
sim('nonlinearEcuaciones');

graphInTime(position.time, position.signals.values, 'Estado $x1 = x$ con $\theta_{0}= 0[^{\circ}]$. Pendulo' , [7 15], 'm',1, 'b');
graphInTime(position_sim.time+3, position_sim.signals.values, 'Estado $x1 = x$ con $\theta_{0}= 0[^{\circ}]$. Pendulo Simulado' , [7 15], 'm',0, 'm');
graphInTime(banda0.time, banda0.signals.values, 'banda' , [7 15], 'm',0, 'g');
graphInTime(banda0.time, banda0.signals.values+0.02, 'banda' , [7 15], 'm',0, 'r');
graphInTime(banda0.time, banda0.signals.values-0.02, 'banda' , [7 15], 'm',0, 'r');
myAnotations(position.time, position.signals.values, position_sim.signals.values, '[m]');
% xlim([5 15])

graphInTime(theta.time, theta.signals.values, 'Estado $x2 = \theta$ con $\theta_{0}= 0[^{\circ}]$. Pendulo' , [7 15], '°',1, 'b');
graphInTime(theta_sim.time+3, theta_sim.signals.values, 'Estado $x2 = \theta$ con $\theta_{0}= 0[^{\circ}]$. Pendulo Simulado' , [7 15], '°',0,'m');
graphInTime(banda.time, banda.signals.values, 'banda' , [7 15], 'm',0, 'g');
graphInTime(banda.time, banda.signals.values+3.7, 'banda' , [7 15], 'm',0, 'r');
graphInTime(banda.time, banda.signals.values-3.7, 'banda' , [7 15], 'm',0, 'r');
myAnotations(theta.time, theta.signals.values, theta_sim.signals.values, '[°]');
% xlim([5 15])

graphInTime(linealVel.time, linealVel.signals.values, 'Estado $x3 = \dot{x}$ con $\theta_{0}= 0[^{\circ}]$. Pendulo' , [7 15], 'm/s',1, 'b');
graphInTime(linealVel_sim.time+3, linealVel_sim.signals.values, 'Estado $x3 = \dot{x}$ con $\theta_{0}= 0[^{\circ}]$. Pendulo Simulado' , [7 15], 'm/s',0, 'm');
graphInTime(banda0.time, banda0.signals.values, 'banda' , [7 15], 'm',0, 'g');
graphInTime(banda0.time, banda0.signals.values+0.02, 'banda' , [7 15], 'm',0, 'r');
graphInTime(banda0.time, banda0.signals.values-0.02, 'banda' , [7 15], 'm',0, 'r');
myAnotations(linealVel.time, linealVel.signals.values, linealVel_sim.signals.values, '[m/s]');
% xlim([5 15])

graphInTime(angularVel.time, angularVel.signals.values, 'Estado $x4 = \dot{\theta}$ con $\theta_{0}= 0[^{\circ}]$. Pendulo' , [7 15], '°/s',1, 'b');
graphInTime(angularVel_sim.time+3, angularVel_sim.signals.values, 'Estado $x4 = \dot{\theta}$ con $\theta_{0}= 0[^{\circ}]$. Pendulo Simulado' , [7 15], '°/s',0, 'm');
graphInTime(banda0.time, banda0.signals.values, 'banda' , [7 15], 'm',0, 'g');
graphInTime(banda0.time, banda0.signals.values+0.02*180/pi, 'banda' , [7 15], 'm',0, 'r');
graphInTime(banda0.time, banda0.signals.values-0.02*180/pi, 'banda' , [7 15], 'm',0, 'r');
myAnotations(angularVel.time, angularVel.signals.values, angularVel_sim.signals.values, '[°/s]');
% xlim([5 15])