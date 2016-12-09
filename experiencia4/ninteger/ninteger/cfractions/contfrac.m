function [a, b] = contfrac (x, n)

% [a, b] = contfrac (x, n)
% This function reckons a continued fraction approximation for x,
% up to n terms. This is given by
%               b1
% a0 + ---------------------
%                 b2
%      a1 + ---------------
%                   b3
%           a2 + ---------
%           
%                a3 + ...

a = floor(x);
b = 0;
x = x - a;
for i = 1:n
    if x == 0 % if there is nothing more to expand... (see note at the end)
        break
    end
    x = 1 / x;
    a = [a floor(x)];
    b = [b 1];
    x = x - a(end);
end
if i < n % if the expansion was not carried out up to the end...
    a = [a ones(1, n-i)];
    b = [b zeros(1, n-i)];
end
% Important note: The test x == 0 does not always work since
% the internal representation of decimal fractions is not exact.
% So sometimes expansion is carried out further than it should,
% resulting in absurdly large values for irrelevant entries of a.