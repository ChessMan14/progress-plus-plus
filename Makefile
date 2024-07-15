progress.a: factory.cpp progress.cpp
	c++ -c factory.cpp -O2
	c++ -c progress.cpp -O2
	ar cr progress.a factory.o progress.o
	rm factory.o progress.o
