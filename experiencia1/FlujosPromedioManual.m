
H = 79.8;  %[cm]
R = 34.5;  %[cm]

h1 = 45.5;
dt1 = 525.9-12.3;
V_30 = (1/3)*pi*h1*((R/H)*h1)^2;
F_30 = int16(V_30/dt1);

h2 = 65.013;
dt2 = 560.8-6;
V_47 = (1/3)*pi*h2*((R/H)*h2)^2;
F_47 = int16(V_47/dt2);

h3 = 65.04;
dt3 = 362.8-5.5;
V_65 = (1/3)*pi*h3*((R/H)*h3)^2;
F_65 = int16(V_65/dt3);

h4 = 66.94;
dt4 = 391.8-5;
V_83 = (1/3)*pi*h4*((R/H)*h4)^2;
F_83 = int16(V_83/dt4);

h5 = 67;
dt5 = 278.2-4.5;
V_100 = (1/3)*pi*h5*((R/H)*h5)^2;
F_100 = int16(V_100/dt5);

disp(dt1);
disp(F_30)

disp(dt2);
disp(F_47)

disp(dt3);
disp(F_65)

disp(dt4);
disp(F_83)

disp(dt5);
disp(F_100)