function C = matsudaCFE(w, gain)

% function C = matsudaCFE(w, gain)
% This function returns a transfer function
% which is the Matsuda approximation of the transfer function
% that has the given gain (in dB) at frequencies w (in rad/s).
% Duarte Valério 2003

% function to interpolate
f = abs(10.^(gain/20));

% coefficients
d = [];
alpha = [];
for j=0:length(w)-1 % frequencies (columns) are swept
    d(0+1,j+1) = f(j+1);
    for i=1:j % functions (lines) are swept
        d(i+1,j+1) = (w(j+1)-w(i)) / (d(i,j+1)-d(i,i));
    end
    alpha = [alpha d(j+1,j+1)];
end % d_i(w_j) is to be found at d(i+1,j+1)

% interpolating function
C = tf(alpha(end));
for i = length(alpha)-2:-1:0
    C = alpha(i+1) + (tf([1 -w(i+1)],[1]) / C);
end