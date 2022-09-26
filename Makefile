main: photoEffect.cgi htmlGenerator

photoEffect.cgi: Sunset.o Grayscale.o Effect.o Invert.o photoEffect.cpp
	g++ Sunset.o Grayscale.o Invert.o Effect.o photoEffect.cpp -o cgi-bin/photoEffect.cgi

Effect.o: Effect.cpp
	g++ Effect.cpp -o Effect.o -c

Sunset.o: Sunset.cpp Effect.o
	g++ Sunset.cpp -o Sunset.o -c

Grayscale.o: Grayscale.cpp Effect.o
	g++ Grayscale.cpp -o Grayscale.o -c

Invert.o: Invert.cpp Effect.o
	g++ Invert.cpp -o Invert.o -c

htmlGenerator: htmlGenerator.cpp direntry.cpp
	g++ htmlGenerator.cpp direntry.cpp -o htmlGenerator


clear: 
	rm *.o cgi-bin/photoEffect.cgi output_photo/* htmlGenerator



