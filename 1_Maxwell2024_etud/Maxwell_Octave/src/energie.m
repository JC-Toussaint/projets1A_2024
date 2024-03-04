function [T ] = energie( gp )
% energie

T=sum(gp.vx.^2+gp.vy.^2)/gp.NP;

end

