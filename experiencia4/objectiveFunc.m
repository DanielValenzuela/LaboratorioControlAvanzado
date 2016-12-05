proportionalTerm = K( 1 );
integralTerm = (K(2)/(wcg^K(3)))∗(cos(pi∗K(3)/2)−1 j∗sin(pi∗K(3)/2));
derivativeTerm = (K(4)∗wcg^K(5))∗(cos(pi∗K(5)/2)+1 j∗sin(pi∗K(5)/2));
C_jw = (proportionalTerm+integralTerm+derivativeTerm);
G_jw = K11/(1 j∗wcg+n11);

fun = @(K)abs(abs(C_jw∗G_jw)−1);