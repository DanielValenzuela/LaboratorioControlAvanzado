function C = nipid(kp, kd, vd, ki, vi, bandwidth, n, formula,...
    expansion, decomposition)

% function C = nipid(kp, kd, vd, ki, vi, bandwidth, n, formula,...
%     expansion, decomposition)
% This function provides integer approximations of fractional PIDs,
% with transfer function kp + kd*D^vd + ki*D^(-vi).
% Type help nid for information on parameters bandwidth to decomposition.
% Duarte Valério 2004

if nargin < 10
    decomposition = 'frac';
end
if nargin < 9
    expansion = 'mcltime';
end
if isempty(expansion)
    expansion = 'mcltime';
end
switch formula
    case {'crone', 'carlson', 'cfehigh', 'cfelow'}
        C = kp +...
            nid(kd, vd, bandwidth, ceil(n/2), formula, expansion, decomposition) +...
            nid(ki, -vi, bandwidth, ceil(n/2), formula, expansion, decomposition);
    case 'matsuda'
        if length(bandwidth) < 2
            error('Variable bandwidth should consist of two frequencies.')
        end
        % function to interpolate
        w = logspace(log10(bandwidth(1)), log10(bandwidth(2)), n+1);
        gain = 20 * log10(abs(kp + kd*(j*w).^vd + ki*(j*w).^(-vi)));
        % function matsudaCFE handles the rest
        C = matsudaCFE(w, gain);
    otherwise
        switch expansion
            case 'mcltime'
                C = kp +...
                    nid(kd, vd, bandwidth, n, formula, expansion, decomposition) +...
                    nid(ki, -vi, bandwidth, n, formula, expansion, decomposition);
            case 'cfe'
                C = kp +...
                    nid(kd, vd, bandwidth, ceil(n/2), formula, expansion, decomposition) +...
                    nid(ki, -vi, bandwidth, ceil(n/2), formula, expansion, decomposition);
            case 'mcltimeINV'
                C = kp +...
                    nid(kd, vd, bandwidth, ceil(n/4), formula, expansion, decomposition) +...
                    nid(ki, -vi, bandwidth, ceil(n/4), formula, expansion, decomposition);
            case 'cfeINV'
                if isinteger(n/2) & ~isinteger(n/4)
                    C = kp +...
                        nid(kd, vd, bandwidth, ceil(n/2)+1, formula, expansion, decomposition) +...
                        nid(ki, -vi, bandwidth, ceil(n/2)+1, formula, expansion, decomposition);
                else
                    C = kp +...
                        nid(kd, vd, bandwidth, ceil(n/2), formula, expansion, decomposition) +...
                        nid(ki, -vi, bandwidth, ceil(n/2), formula, expansion, decomposition);
                end
            otherwise
                error ('The expansion has an invalid format.');
        end
end
