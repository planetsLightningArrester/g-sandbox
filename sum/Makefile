# Rebuild all
all: main
main: main.o sum.o
	g++ -o build/main build/main.o build/sum.o

# Rebuild sum
sum.o: sum/sum.cpp sum/sum.h
	g++ -c sum/sum.cpp -o build/sum.o

# Rebuild main
main.o: main.cpp
	g++ -c main.cpp -o build/main.o
