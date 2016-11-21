function tsIndex = findTs(resp)
	intersections = 0;
	index = 1;
	for i=1:1:length(resp)
		if abs(resp(i)-180)<0.1
			intersections = intersections + 1;
			index = i;
			abs(resp(i)-180);
		end
		if (intersections==3)
			break;
		end
	end
	if index == 1
		display('STDERR: No Intersection found');
	end
	tsIndex = index;
end