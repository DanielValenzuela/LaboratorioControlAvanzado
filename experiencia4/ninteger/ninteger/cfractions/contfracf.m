function [a, b] = contfracf (c, n)

% [a, b] = contfracf (c, n)
% This function reckons a continued fraction approximation for
%        c10 + c11 * x + c12 * x^2 + ...
% f(x) = -------------------------------
%        c00 + c01 * x + c02 * x^2 + ...
% up to n terms. This is given by
%               b1
% a0 + ---------------------
%                b2 * x
%      a1 + ---------------
%                  b3 * x
%           a2 + ---------
%           
%                a3 + ...

c = [c [0; 0]]; % unknown coefficients are assumed 0
for j = 2:n
    for i = 0:size(c,2)-2 % -2 since the last column contains only 0s
        % indexes should vary beginning in 0, and so must always be added 1 in what follows
        c(j+1,i+1) = c(j-1+1,0+1) * c(j-2+1,i+1+1) - c(j-2+1,0+1) * c(j-1+1,i+1+1);
    end
end
a = [0 c((0:n-1)+1,1)'];
b = [0 c((1:n)+1,1)'];