function output = isinteger(a)

% function output = isinteger(a)
% This function returns 1 if a is an integer and 0 if it is not.
% If a is complex and 1 is returned,
% this means that both the real and the imaginary parts are integer.
% If a is a matrix, a matrix of ones and zeros is returned.
% Duarte Valério 2003

output = ((a - round(a)) == 0);