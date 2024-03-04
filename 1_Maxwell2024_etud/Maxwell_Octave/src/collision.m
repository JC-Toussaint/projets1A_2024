function [np1, np2, taumin ] = collision( gp )
% determination du premier choc binaire
% et de l'instant de collision

taumin=realmax; % valeur max d'un reel
tau  =realmax;
np1 = 0;
np2 = 0;
for i=1:gp.NP-1
    for j=i+1:gp.NP
        dx =gp.x (i)-gp.x (j); % (OM1-OM2)°=(M2M1)°
        dy =gp.y (i)-gp.y (j);
        dvx=gp.vx(i)-gp.vx(j); % (v1-v2)°
        dvy=gp.vy(i)-gp.vy(j);
        
        delta=(dx*dvx+dy*dvy)^2-(dvx^2+dvy^2)*(dx^2+dy^2-4*gp.a^2);
        if delta>0
            tau=((-dx*dvx-dy*dvy)-sqrt(delta))/(dvx^2+dvy^2);
        end
        
        if (tau > 0) && (tau<taumin)
                taumin=tau;
                np1=i; np2=j;
        end
        
    end
end

end

