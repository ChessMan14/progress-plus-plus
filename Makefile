progress.o: factory.cpp progress.cpp
	c++ -c factory.cpp
	c++ -c progress.cpp
	ar cr progress.a factory.o progress.o
	rm factory.o progress.o
