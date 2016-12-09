function C = nidiz(k, v, n, Ts, formula, expansion)

% function C = nidiz(k, v, n, Ts, formula, expansion)
% is the same as
% C = nid(k, v, Ts, n, formula, expansion, 'all');
% This function is obsolescent and its use should be avoided.
% Duarte Valério 2004

C = nid(k, v, Ts, n, formula, expansion, 'all');