function myAnotations(time, signal1, signal2, units)
	% dt = time(10)-time(9);
	% n1 = 45;
	% y1 = signal1(n1);
	% y2 = signal2(n1);
	% xa = [0.8 0.8];
	% ya = [y1 y2];
	% [xaf,yaf] = ds2nfu(xa,ya);

	% n2 = length(time)-1;
	% z1 = signal1(n2);
	% z2 = signal2(n2);
	% xa2 = [0.99 0.99];
	% ya2 = [z1 z2];
	% [xaf2,yaf2] = ds2nfu(xa2,ya2);

	% annotation('arrow', xaf, yaf);
	% annotation('arrow', xaf2, yaf2);
	
	legend('Real','Simulado')

	% dim = [0.5 0.2 0.3 0.3];
	% dim2 = [0.7 0.4 0.3 0.3];
	% err1 = y2-y1;
	% err2 = z2-z1;
	% % perErr1 = abs(err1/y1)*100
	% str1 = strcat('error = ',num2str(err1), units);
	% str2 = strcat('error = ',num2str(err2), units);
	% annotation('textbox',dim,'String',str1,'FitBoxToText','on');
	% annotation('textbox',dim2,'String',str2,'FitBoxToText','on');
end