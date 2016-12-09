% NINTEGER - Non-integer (fractional) control toolbox
% Version 2.3 Duarte Vale'rio 2005 / 08 / 17
%
% Approximations of fractional order controllers (35 methods available)
%   nid - approximates a fractional derivative
%   nipid - approximates a fractional PID
%   crone1 - first-generation CRONE approximation (real or complex)
%   newton - generalisation of Carlson method (for any controller structure)
%   matsudaCFE - Matsuda method (for any controller structure)
%
% Functions for controllers ensuring a constant phase open-loop
%   crone2 - second-generation CRONE approximation, in the frequency domain
%   crone2z - same as above, in the discrete-time domain
%
% Functions for controllers ensuring a constant slope phase open-loop
%   crone3 - returns the parameters for a third-generation CRONE
%
% Identification of fractional models from frequency response data
%   hartley - identification of a model with numerator or denominator equal to 1
%   levy - identification of a model with numerator and denominator
%   vinagre - improvement of levy with better low-frequency fit
%   sanko - iterative improvement of levy
%   lawro - incorporation of additional data into a pre-existent model
%
% Functions for analysing fractional plants
%   freqrespFr - frequency response of a fractional plant
%   bodeFr - Bode plots of a fractional plant
%   nyquistFr - Nyquist plot of a fractional plant
%   nicholsFr - Nichols plot of a fractional plant
%   sigmaFr - singular values plot of a fractional plant
%   normh2Fr - H2 norm of a fractional plant
%   normhinfFr - Hinf norm of a fractional plant
%
% Graphical interface
%   ninteger
%
% Simulink library
%   nintblocks
%
% Functions for working with continued fractions
%   contfrac - returns a continued fraction expansion of a real number
%   contfracf - returns a continued fraction expansion of a rational function
%   contfraceval - evaluates a continued fraction expansion of a real number
%   contfracfeval - evaluates a continued fraction expansion of a rational function
%
% Obsolescent functions (included for compatibility with older versions)
%   carlson - Carlson approximation, in the frequency domain
%   matsuda - Matsuda approximation, in the frequency domain
%   nidiz - thirty-two approximations, in the discrete-time domain
%   nipidcrone - PID with crone1 approximated derivative and integral parts
%   nipidcarlson - PID with carlson approximated derivative and integral parts
%   nipidmatsuda - PID with matsuda approximated derivative and integral parts
%   nipidz - PID with nidiz approximated derivative and integral parts