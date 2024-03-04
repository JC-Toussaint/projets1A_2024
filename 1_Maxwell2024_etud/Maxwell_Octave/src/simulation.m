function [gp ] = simulation( gp )
% dynamique du gaz
DEBUG   =1;
GRAPH   =1;
CUMHISTO=0;

% histogramme bins
binrange = linspace(-2*gp.v0, +2*gp.v0, 41);
%counts   = histcounts(gp.vx, binrange);

disp('Running')

iter=0;
while(1)
    
    %    [np1, np2, tau ] = collision ( gp )
    [np1, np2, tau ] = collision_optim( gp );
    assert(np1 > 0);
    assert(np2 > 0);
    
    dx =gp.x (np1)-gp.x (np2);
    dy =gp.y (np1)-gp.y (np2);
    dvx=gp.vx(np1)-gp.vx(np2);
    dvy=gp.vy(np1)-gp.vy(np2);
    
    if DEBUG
        res=(dx+tau*dvx)^2+(dy+tau*dvy)^2-4*gp.a^2;
        ['iteration ', num2str(iter) ' tau ' num2str(tau) ' residu ' num2str(res)]
        %['energie ' num2str(energie(gp))]
        %pause(1)
    end
    
    if GRAPH
        fig=figure(1);
        if ~(mod(iter, 10)) clf(fig,'reset'); end
        gp.tau=tau;
        gp.np1=np1;
        gp.np2=np2;
        dessine(gp, [0, 0, 0]);
        drawnow;
    end
    
    [gp ] = evolution_optim( gp, tau );
    [gp ] = speculaire( gp, np1, np2 );
    
%    if ~(mod(iter, 100))
%        ['iteration ', num2str(iter)]
%        
%        fig=figure(2);
%        clf(fig,'reset');
%        
%        if CUMHISTO
%            counts = counts + histcounts(gp.vx, binrange);
%            bar(binrange(1:end-1), counts./sum(counts), 'b')
%        else
%            h = histogram([gp.vx], 41);
%        end
%        drawnow;
%    end
    iter=iter+1;
end

end

