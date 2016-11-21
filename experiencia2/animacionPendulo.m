figure(1);
for k=1:length(theta.time);
	% hold on
	thetaAux = theta.signals.values(k)*pi/180;
	arg = thetaAux-(pi/2);
	if (k+1<length(theta.signals.values))
		if (theta.signals.values(k+1)<theta.signals.values(k))
			marker = 'ro-';
		else
			marker = 'bo-';
		end
	end
	plot([0,1*exp(j*arg)],marker);
	axis equal;
	axis(1.2*[-1 1 -1 1]);
	grid on;
	drawnow;
	pause();
end