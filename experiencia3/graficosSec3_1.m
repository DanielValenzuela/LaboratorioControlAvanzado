clear all
close all
clc

%PI
% load('DATOS/PIRef5Pert.mat')
% load('DATOS/PIRef0.mat')
% sim('modeloReferencia')
% graphInTime(alphaVertical.time, alphaVertical.signals.values, 'Angulo vertical twin rotor' , [0 70], 'b',1, 'b');

% % graphInTime(band5.time, band5.signals.values, 'band' , [0 20], 'rad/s',0, 'r');
% % graphInTime(band5.time, band5.signals.values*1.05, 'band' , [0 20], 'rad/s',0, 'k');
% % graphInTime(band5.time, band5.signals.values*(1-0.05), 'band' , [0 20], 'rad/s',0, 'k');

% graphInTime(band0.time, band0.signals.values, 'band' , [0 70], 'rad/s',0, 'r');
% graphInTime(band0.time, band0.signals.values+0.25, 'band' , [0 70], 'rad/s',0, 'k');
% graphInTime(band0.time, band0.signals.values-0.25, 'band' , [0 70], 'rad/s',0, 'k');

% graphInTime(alphaHorizontal.time, alphaHorizontal.signals.values, 'Angulo Horizontal twin rotor' , [0 100], 'b',1, 'b');

%PID
% load('DATOS/DATOS3PID.mat')
% graphInTime(alphaHorizontal.time, alphaHorizontal.signals.values, 'Angulo Horizontal twin rotor' , [0 100], 'b',1, 'b');
% graphInTime(band170.time, band170.signals.values, 'band' , [0 100], 'rad/s',0, 'r');
% graphInTime(band170.time, band170.signals.values*1.05, 'band' , [0 100], 'rad/s',0, 'k');
% graphInTime(band170.time, band170.signals.values*(1-0.05), 'band' , [0 100], 'rad/s',0, 'k');

% graphInTime(alphaVertical.time, alphaVertical.signals.values, 'Angulo vertical twin rotor' , [0 100], 'b',1, 'b');

%Op Conjunta
load('DATOS/PERT_ACOPLADOS.mat')
sim('modeloReferencia')
graphInTime(alphaVertical.time, alphaVertical.signals.values, 'Angulo vertical twin rotor' , [0 250], 'b',1, 'b');
graphInTime(band5.time, band5.signals.values, 'band' , [0 250], 'rad/s',0, 'r');
graphInTime(band5.time, band5.signals.values*1.05, 'band' , [0 250], 'rad/s',0, 'k');
graphInTime(band5.time, band5.signals.values*(1-0.05), 'band' , [0 250], 'rad/s',0, 'k');

graphInTime(alphaHorizontal.time, alphaHorizontal.signals.values, 'Angulo Horizontal twin rotor' , [0 250], 'b',1, 'b');
graphInTime(band170.time, band170.signals.values, 'band' , [0 250], 'rad/s',0, 'r');
graphInTime(band170.time, band170.signals.values*1.05, 'band' , [0 250], 'rad/s',0, 'k');
graphInTime(band170.time, band170.signals.values*(1-0.05), 'band' , [0 250], 'rad/s',0, 'k');