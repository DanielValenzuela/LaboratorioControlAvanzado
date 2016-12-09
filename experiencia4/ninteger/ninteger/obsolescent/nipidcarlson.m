function C = nipidcarlson(kp, kd, ad, ki, ai, wc, n)

% function C = nipidcarlson(kp, kd, dv, ki, vi, wl, wh, n)
% is the same as
% C = nipid(kp, kd, 1/ad, ki, 1/ai, wc, n, 'carlson', [], 'all');
% This function is obsolescent and its use should be avoided.
% Duarte Valério 2004

C = nipid(kp, kd, 1/ad, ki, 1/ai, wc, n, 'carlson', [], 'all');