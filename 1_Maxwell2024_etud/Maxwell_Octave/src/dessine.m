function dessine( gp, color )
% dessin des trajectoires

NT=10;
dt=gp.tau/NT;
xlim([-gp.L gp.L]);
ylim([-gp.L gp.L]);
np1=gp.np1; np2=gp.np2;

hold on;
for nt=1:NT % ---1---2---3---nt---NT
    color0=[1 1 1];
%    plot(gp.x, gp.y, '.', 'MarkerEdgeColor', color0, 'MarkerFaceColor', color0);
    [gp ] = evolution_optim( gp, dt );
    plot(gp.x, gp.y, '.', 'MarkerEdgeColor', color, 'MarkerFaceColor', color);
    plot([gp.x(np1) gp.x(np2)], [gp.y(np1) gp.y(np2)], '.', ...
        'MarkerEdgeColor', [1 0 0], 'MarkerFaceColor', [1 0 0]);
%     for i=1:gp.NP
%         circle(gp.x(i), gp.y(i), gp.a, color);
%     end
%    hold on
%    drawnow;
end

circle(gp.x(np1), gp.y(np1), 2*gp.a, [1 0  0]);
circle(gp.x(np2), gp.y(np2), 2*gp.a, [1 0  0]);

end

