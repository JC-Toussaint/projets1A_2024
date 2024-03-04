function [gp ] = evolution( gp, tau )
% mise a jour des positions

% conditions periodiques uniquement
for i=1:gp.NP
    xp=gp.x(i)+gp.vx(i)*tau;
    yp=gp.y(i)+gp.vy(i)*tau;
    
    if xp<-gp.L, xp=xp+2*gp.L; end
    if xp>+gp.L, xp=xp-2*gp.L; end
    if yp<-gp.L, yp=yp+2*gp.L; end
    if yp>+gp.L, yp=yp-2*gp.L; end
    gp.x(i)=xp;
    gp.y(i)=yp;
end

end

