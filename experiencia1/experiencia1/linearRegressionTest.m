load accidents
x = hwydata(:,14); %Population of states
y = hwydata(:,4); %Accidents per state
linearRegression(y,x)