function C = matsuda(k, v, wl, wh, n)

% function C = matsuda(k, v, wl, wh, n)
% is the same as
% C = nid(k, v, [wl wh], n, 'matsuda', [], 'all');
% This function is obsolescent and its use should be avoided.
% Duarte Valério 2004

C = nid(k, v, [wl wh], n, 'matsuda', [], 'all');