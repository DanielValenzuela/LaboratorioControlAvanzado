figure(1);
for k=1:length(theta.time);
	%hold on
	plot([0,1*exp(j*(theta.signals.values(k)-(pi/2)))],'o-');
	axis equal;
	axis(1.2*[-1 1 -1 1]);
	grid on;
	drawnow;
	pause();
end