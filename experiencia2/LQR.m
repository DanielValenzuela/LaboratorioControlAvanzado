%% Controlador LQR
A = [0 0 1 0; 0 0 0 1; 0 0.5401 -0.7235 0; 0 14.0955 -0.9854 0];
B = [0  0 2.2747 3.0978]';
C = [1 0 0 0;0 1 0 0];
Q = [5000 0 0 0;0 0 0 0; 0 0 100 0; 0 0 0 0] ;
D = 0;
R = 1;
K = lqr(A,B,Q,R);
Ac = (A-B*K);
Bc = B;
Cc = C;
Dc = D;
X0 = [0;4*pi/3;0;0];
states = {'x' 'theta' 'x_dot' 'theta_dot'};
inputs = {'r'};
outputs = {'x','theta'};

sys_cl = ss(Ac,Bc,Cc,Dc,'statename',states,'inputname',inputs,'outputname',outputs);
sys_tf =tf(sys_cl)

t = 0:0.01:5;
r =10*ones(size(t));

[y,t,x]=lsim(sys_cl,r,t,X0);
%plot(t,y(:,1))
y(:,2) = 180/pi.*y(:,2);

[AX,H1,H2] = plotyy(t,y(:,1),t,y(:,2),'plot');
xlabel('Time [s]')
set(get(AX(1),'Ylabel'),'String','cart position (m)')
set(get(AX(2),'Ylabel'),'String','pendulum angle (grades)')

title('Step Response with LQR Control with initial condition 4pi/3')