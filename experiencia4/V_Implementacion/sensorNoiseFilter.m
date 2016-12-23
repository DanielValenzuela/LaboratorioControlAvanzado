function filterSignal = sensorNoiseFilter(noisy_signal_vect)
	time = [];
	signal = [];
	tolerance = 1; %[cm]
	real_t = noisy_signal_vect(:,1);
	i = 1;
	n = 1;

	for t = real_t'
		if (t<=400 && (22.5-tolerance <= noisy_signal_vect(i,2)) && (noisy_signal_vect(i,2) <= 22.5+tolerance))
			time(n) = t;
			signal(n) = noisy_signal_vect(i,2);
			n = n+1;
		elseif (400<t && t<=800 && (37.5-tolerance <= noisy_signal_vect(i,2)) && (noisy_signal_vect(i,2) <= 37.5+tolerance))
			time(n) = t;
			signal(n) = noisy_signal_vect(i,2);
			n = n+1;
		elseif (800<t && t<=1200 && (52.5-tolerance <= noisy_signal_vect(i,2)) && (noisy_signal_vect(i,2) <= 52.5+tolerance))
			time(n) = t;
			signal(n) = noisy_signal_vect(i,2);
			n = n+1;
		elseif (1200<t && t<=1600 && (37.5-tolerance <= noisy_signal_vect(i,2)) && (noisy_signal_vect(i,2) <= 37.5+tolerance))
			time(n) = t;
			signal(n) = noisy_signal_vect(i,2);
			n = n+1;
		elseif (1600<t && t<=2000 && (22.5-tolerance <= noisy_signal_vect(i,2)) && (noisy_signal_vect(i,2) <= 22.5+tolerance))
			time(n) = t;
			signal(n) = noisy_signal_vect(i,2);
			n = n+1;
		elseif (2000<t && t<=2400 && (15-tolerance <= noisy_signal_vect(i,2)) && (noisy_signal_vect(i,2) <= 15+tolerance))
			time(n) = t;
			signal(n) = noisy_signal_vect(i,2);
			n = n+1;
		else
			% Filter point
				
		end
		i = i+1;
	end
	filterSignal = struct('time', time,'signal_values',signal);
end