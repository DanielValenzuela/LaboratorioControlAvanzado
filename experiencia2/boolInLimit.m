function inLimit = boolInLimit(vector)
	if (max(vector)<=1 || min(vector)>=-1)
		inLimit = 1;
	else
		inLimit = 0;
	end
end