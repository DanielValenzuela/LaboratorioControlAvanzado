function [ fiteredData, timeData ] = myFilt(structData, minH, maxH)
    ColumData = structData.signals.values;
    N = length(ColumData);
    counter = 1;
    for i=1:N
        if ColumData(i) > minH && ColumData(i) < maxH
            fiteredData(counter) = ColumData(i);
            timeData(counter) = structData.signals.values(i);
            counter = counter+1;
        end
    end
    
    fiteredData = fiteredData';
    timeData = timeData';
end