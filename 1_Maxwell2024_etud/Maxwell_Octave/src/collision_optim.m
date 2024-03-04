function [np1, np2, tauMin ] = collision_optim( gp )
% determination du premier choc binaire
% et de l'instant de collision
% programmation vectorielle

tauMin=realmax; % valeur max d'un reel
tau  =realmax;
np1 = 0;
np2 = 0;

[ Xg,  Xd]=meshgrid(gp.x,  gp.x);
[ Yg,  Yd]=meshgrid(gp.y,  gp.y);
[VXg, VXd]=meshgrid(gp.vx, gp.vx);
[VYg, VYd]=meshgrid(gp.vy, gp.vy);

DX = Xg- Xd;
DY = Yg- Yd;
DVX=VXg-VXd;
DVY=VYg-VYd;

DELTA=(DX.*DVX+DY.*DVY).^2-(DVX.^2+DVY.^2).*(DX.^2+DY.^2-4*gp.a^2);
[m]= find(DELTA(:)>0);
if isempty(m)
    error('pas de collision');
end
    
TAU=zeros(size(DELTA));
TAU(m)=((-DX(m).*DVX(m)-DY(m).*DVY(m))-sqrt(DELTA(m)))./(DVX(m).^2+DVY(m).^2);

[p]= find(TAU(:)>0);
[tauMin]= min(TAU(p));
eps=1e-9;
[row, col] = find(abs(TAU-tauMin)<eps);

np1=col(1);
np2=row(1);

assert(tauMin>0);
end

