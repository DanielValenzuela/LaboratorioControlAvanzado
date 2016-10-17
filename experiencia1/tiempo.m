function z = tiempo(h,A,B,C)
z = -2.*A.*C.*log(C-B.*sqrt(h))./(B.^2) + 2.*A.*C.*log(C)./(B.^2) - 2.*A.*sqrt(h)./B;
end

