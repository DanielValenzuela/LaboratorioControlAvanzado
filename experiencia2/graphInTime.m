function [ ] = graphInTime( t_vector, t_signal, name , limits, units, newFigure, c)
	% Graph in time
	%figure('Name',strcat('Señal', name),'NumberTitle','off');
	if (newFigure==1)
		% hold off
		figure('Name', name,'NumberTitle','off');
	else
		hold on
	end
	plot(t_vector,t_signal, c);        % Grafico de la señal 
	xlim(limits)
	title(strcat('Grafico de ',name,' en el Tiempo'), 'interpreter', 'latex')
	xlabel('Tiempo [s]'); ylabel(strcat('Amplitud [ ', units, ' ]'));
end