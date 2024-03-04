%
% programme de dynamique moleculaire
% Phelma JC Toussaint
%

clc
clear all
close all

gp.NP=100;
gp.L =1;
gp.seed=123;

[ gp ] = init( gp );
[ gp ] = simulation( gp );

