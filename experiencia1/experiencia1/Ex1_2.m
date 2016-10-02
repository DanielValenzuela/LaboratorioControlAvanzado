close all
clear all
clc
R = 34.5;
H = 79.8;
c1 = 0.01;
c2 = 0.01;
f = 30; % 0 a 50
B = 0.034;
A = pi*(R^2)/(H^2);
C = c1*f + c2;
h = 0:0.1:H;
t= tiempo(h,A,B,C);
plot(t, h)
xlabel('Tiempo[s]')
ylabel('Altura[cm]')
title('Altura estanque en función del tiempo')