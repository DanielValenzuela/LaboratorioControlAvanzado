function k = setK_lqr(Q)
	A = [0 0 1 0; 0 0 0 1; 0 0.5401 -0.7235 0; 0 14.0955 -0.9854 0];
	B = [0  0 2.2747 3.0978]';
	C = [1 0 0 0; 0 1 0 0];
	%Q = [0.1 0 0 0; 0 1 0 0; 0 0 0.1 0; 0 0 0 20];
	D = 0;
	R = 1;
	k = lqr(A,B,Q,R);
end