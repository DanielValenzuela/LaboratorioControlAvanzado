function [ fiteredData, timeData ] = myFilt2(structData, maxH, minH)
    %ColumData = structData.signals.values;
    ColumData = structData.signal;
    N = length(ColumData);

    for i=70:N
        if ColumData(i) < maxH
            minIndex = i;
            break;
        end
    end

    for i=1:N
        if ColumData(N-i+1) > minH
            maxIndex = N-i+1;
            break;
        end
    end

    fiteredData = ColumData(minIndex:maxIndex);
    timeData = structData.time(minIndex:maxIndex);

    %ColumData(minIndex)
    %ColumData(maxIndex)

    %disp(strcat('Number of data left: ',32,int2str(counter)))
    
    fiteredData = fiteredData';
    timeData = timeData';
end