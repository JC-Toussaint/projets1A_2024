all:
	gcc example.c gfx.c -o example -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm
	gcc example2.c gfx.c -o example2 -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm
	gcc example3.c gfx.c -o example3 -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm

clean:
	rm -f example example2 example3
