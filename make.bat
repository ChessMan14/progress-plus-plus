@ECHO OFF
g++ -c factory.cpp -O2
g++ -c progress.cpp -O2
ar cr progress.lib factory.o progress.o
del factory.o progress.o
