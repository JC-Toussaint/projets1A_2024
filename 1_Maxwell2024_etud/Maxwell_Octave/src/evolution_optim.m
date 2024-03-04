function [gp ] = evolution_optim( gp, tau )
% mise a jour des positions
% programmation vectorielle
PERIODIC=0;

gp.x=gp.x+gp.vx*tau;
gp.y=gp.y+gp.vy*tau;

if PERIODIC % conditions periodiques
    gp.x=gp.x-2*(gp.x>gp.L)*gp.L+2*(gp.x<-gp.L)*gp.L;
    gp.y=gp.y-2*(gp.y>gp.L)*gp.L+2*(gp.y<-gp.L)*gp.L;
else
    gp.vx=gp.vx-2*gp.vx.*(gp.x>+gp.L)-2*gp.vx.*(gp.x<-gp.L);
    gp.vy=gp.vy-2*gp.vy.*(gp.y>+gp.L)-2*gp.vy.*(gp.y<-gp.L);
    
    gp.x=gp.x+2*(gp.L-gp.x).*(gp.x>+gp.L)-2*(gp.L+gp.x).*(gp.x<-gp.L);
    gp.y=gp.y+2*(gp.L-gp.y).*(gp.y>+gp.L)-2*(gp.L+gp.y).*(gp.y<-gp.L);
end
end

