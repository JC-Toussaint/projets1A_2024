function [ gp ] = init( gp )
% Initialisation de la distribution spatiale
% et de vitesse du gaz de particules

gp.a =1e-2; % rayon des particules
gp.v0=0.1;  % module de la vitesse

%s = rng(gp.seed);

aleat=rand(gp.NP, 1);
gp.vx=gp.v0*cos(2*pi*aleat);
gp.vy=gp.v0*sin(2*pi*aleat);

aleat=rand(gp.NP, 1);
gp.x =gp.L*(2*aleat-1);

aleat=rand(gp.NP, 1);
gp.y =gp.L*(2*aleat-1);

end

