function [ differenceVect ] = myDiff(x,stepTime)
	for i=1:stepTime:length(x)
		if i+stepTime<length(x)
			differenceVect(i)=x(i+stepTime)-x(i);
		end
	end
	differenceVect = differenceVect';
end