function varargout = sigmaFr(F, Q, w)

% [sv, w] = sigmaFr(F, Q, w)
% Singular value plot of a fractional plant. Paramter w may be a vector with the
% frequencies of the plot (in rad/s) or a cell with the limits of the
% frequency range of the plot (in rad/s). If empty a suitable range is
% provided. 
% F is an lti object, and Q the commensurate order (the default value
% of which will be 1). For instance, plant 1/(1+s^.5) correponds to
% F = tf(1,[1 1]) and Q = 0.5.
% A singular value diagram is plot if there are no return values.
% Otherwise the function returns the values (absolute value)
% at frequencies w (in rad/s).
% Duarte Valério 2004

if nargin < 3 % no data on w was provided
    temp = abs([tzero(F); pole(F)]);
    if min(temp)
        wmax = 10^ceil(log10(max(temp))) * 100;
        wmin = 10^floor(log10(min(temp))) / 100;
    else % temp is all zeros
        wmax = 100;
        wmin = .01;
    end
    w = logspace(log10(wmin), log10(wmax), 10 * ceil(log10(wmax/wmin)));
end
% there are 10 frequencies per decade
if iscell(w) % only wmax and wmin were provided
    wmin = w{1};
    wmax = w{2};
    w = logspace(log10(wmin), log10(wmax), 10 * ceil(log10(wmax/wmin)));
end
if nargin < 2, Q = 1; end % integer plants assumed as default

singval = []; % will contain singular values
lines = size(F,1);
columns = size(F,2);
for i = 1:length(w)
    tempMatrix = [];
    for n = 1:lines
        for k = 1:columns
            leng = length(F(n,k).num{1});
            tempNum = 0;
            for m = 1:leng
                tempNum = tempNum + F(n,k).num{1}(leng-m+1) * (j*w(i))^((m-1)*Q);
            end
            tempDen = 0;
            for m = 1:leng
                tempDen = tempDen + F(n,k).den{1}(leng-m+1) * (j*w(i))^((m-1)*Q);
            end
            tempMatrix(n,k) = tempNum / tempDen;
        end
    end
    singval = [singval, svd(tempMatrix)];
end

if nargout == 0 % there are no output variables, draw a plot
    semilogx(w, 20*log10(singval), 'b')
    grid on
    title('Singular values')
    xlabel('frequency / rad s^{-1}')
    ylabel('singular values / dB')
else
    varargout{1} = singval;
    if nargout > 1, varargout{2} = w; end
end