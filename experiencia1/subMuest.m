function [ subMuestX, subMuestTime ] = subMuest(signalStructure,stepTime)
	x = signalStructure.signals.values;
	time = signalStructure.time;
	counter = 1;
	for i=1:1:length(x)
		if mod(i,stepTime)==0
			subMuestX(counter)=x(i);
			subMuestTime(counter)=time(i);
			counter = counter + 1;
	end
end