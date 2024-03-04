function [gp ] = speculaire( gp, np1, np2 )
% traitement des chocs speculaires

cdg.vx=0.5*(gp.vx(np1)+gp.vx(np2));
cdg.vy=0.5*(gp.vy(np1)+gp.vy(np2));

dx =gp.x (np1)-gp.x (np2); % (OM1-OM2)=(M2M1)
dy =gp.y (np1)-gp.y (np2);
dr =sqrt(dx*dx+dy*dy);     % module

nx=-dx/dr; % normale
ny=-dy/dr;
tx=+ny;    % tangente
ty=-nx;

dvx = gp.vx(np1)-gp.vx(np2);
dvy = gp.vy(np1)-gp.vy(np2);
dv=sqrt(dvx*dvx+dvy*dvy);    % module

u1x=dvx/dv;  % unitaire avant choc
u1y=dvy/dv;

u3x=(u1x*tx+u1y*ty)*tx-(u1x*nx+u1y*ny)*nx; % unitaire apres choc speculaire
u3y=(u1x*tx+u1y*ty)*ty-(u1x*nx+u1y*ny)*ny;

v1p=(gp.vx(np1)-cdg.vx)^2+(gp.vy(np1)-cdg.vy)^2;
v1p=sqrt(v1p);  % module de V1'

% mise a jour des vitesses
gp.vx(np1)=cdg.vx+v1p*u3x;
gp.vy(np1)=cdg.vy+v1p*u3y;

gp.vx(np2)=cdg.vx-v1p*u3x;
gp.vy(np2)=cdg.vy-v1p*u3y;

end

