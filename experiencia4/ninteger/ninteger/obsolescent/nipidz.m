function C = nipidz(kp, kd, vd, ki, vi, n, Ts, formula, expansion)

% function C = nipidz(kp, kd, vd, ki, vi, n, Ts, formula, expansion)
% is the same as
% C = nipid(kp, kd, vd, ki, vi, Ts, n, formula, expansion, 'all');
% This function is obsolescent and its use should be avoided.
% Duarte Valério 2004

C = nipid(kp, kd, vd, ki, vi, Ts, n, formula, expansion, 'all');