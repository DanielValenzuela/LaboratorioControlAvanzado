close all
%Non Linear Open Loop  vs Linear Open Loop Graphs

graphInTime(position.time, position.signals.values, 'Estado $x1 = x$ con $\theta_{0}= 0[^{\circ}]$. Modelo No Lineal' , [0 1], 'm',1, 'b');
graphInTime(positionLineal.time, positionLineal.signals.values, 'Estado $x1 = x$ con $\theta_{0}= 0[^{\circ}]$. Modelo Lineal' , [0 1], 'm',0, 'r');
myAnotations(position.time, position.signals.values, positionLineal.signals.values, '[m]');


graphInTime(theta.time, theta.signals.values, 'Estado $x2 = \theta$ con $\theta_{0}= 0[^{\circ}]$. Modelo No Lineal' , [0 1], '°',1, 'b');
graphInTime(thetaLineal.time, thetaLineal.signals.values, 'Estado $x2 = \theta$ con $\theta_{0}= 0[^{\circ}]$. Modelo Lineal' , [0 1], '°',0,'r');
myAnotations(theta.time, theta.signals.values, thetaLineal.signals.values, '[°]');


graphInTime(linealVel.time, linealVel.signals.values, 'Estado $x3 = \dot{x}$ con $\theta_{0}= 0[^{\circ}]$. Modelo No Lineal' , [0 1], 'm/s',1, 'b');
graphInTime(linealVelLineal.time, linealVelLineal.signals.values, 'Estado $x3 = \dot{x}$ con $\theta_{0}= 0[^{\circ}]$. Modelo Lineal' , [0 1], 'm/s',0, 'r');
myAnotations(linealVel.time, linealVel.signals.values, linealVelLineal.signals.values, '[m/s]');


graphInTime(angularVel.time, angularVel.signals.values, 'Estado $x4 = \dot{\theta}$ con $\theta_{0}= 0[^{\circ}]$. Modelo No Lineal' , [0 1], '°/s',1, 'b');
graphInTime(angularVelLineal.time, angularVelLineal.signals.values, 'Estado $x4 = \dot{\theta}$ con $\theta_{0}= 0[^{\circ}]$. Modelo Lineal' , [0 1], '°/s',0, 'r');
myAnotations(angularVel.time, angularVel.signals.values, angularVelLineal.signals.values, '[°/s]');