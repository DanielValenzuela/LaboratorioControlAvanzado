function out = contfraceval (a, b, n)

% out = contfraceval (a, b, n)
% This function evaluates the continued fraction expansion
% given by a = [a0 a1 a2 a3...]
% and b = [b0 b1 b2 b3...]
% where b0 must be 0.
% The continued fraction is
%               b1
% a0 + ---------------------
%                 b2
%      a1 + ---------------
%                   b3
%           a2 + ---------
%           
%                a3 + ...
% Variable out is reckoned for the several values of n
% according to the recursive formulas
% out(n) = P(n) / Q(n)
% P(0) = a0
% Q(0) = 1
% P(-1) = 1
% Q(-1) = 0
% P(n) = a(n) * P(n-1) + b(n) * P(n-2)
% Q(n) = a(n) * Q(n-1) + b(n) * Q(n-2)
% which are more efficient than direct evaluation
% and allow for a progressive reckoning of approximations that keep on improving.
% Of course max(n) should not be greater than length(a)-1 or length(b)-1.
% For obtaining solely the best possible value of the series make n=min[length(a) length(b)]-1.

P = [1 a(1)]; % notice that a(1) is a0
Q = [0 1];
temp = [];
for i = 1:max(n)
    P = [P(2) a(i+1)*P(2)+b(i+1)*P(1)]; % the +1 in the indexes of a and b results of their...
    Q = [Q(2) a(i+1)*Q(2)+b(i+1)*Q(1)]; % ... beginning with the value of order 0
    temp = [temp P(2)/Q(2)]; % no normalization is ever performed
end
out = temp(n);