function C = carlson (k, a, wc, n)

% function C = carlson (k, a, wc, n)
% is the same as
% C = nid(k, v, wc, n, 'carlson', [], 'all');
% This function is obsolescent and its use should be avoided.
% Duarte Valério 2004

C = nid(k, 1/a, wc, n, 'carlson', [], 'all');