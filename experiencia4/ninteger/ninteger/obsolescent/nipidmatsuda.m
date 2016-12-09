function C = nipidmatsuda(kp, kd, vd, ki, vi, wl, wh, n)

% function C = nipidmatsuda(kp, kd, vd, ki, vi, wl, wh, n)
% is the same as
% C = nipid(kp, kd, vd, ki, vi, [wl, wh], n, 'matsuda', [], 'all');
% This function is obsolescent and its use should be avoided.
% Duarte Valério 2004

C = nipid(kp, kd, vd, ki, vi, [wl, wh], n, 'matsuda', [], 'all');