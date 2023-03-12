# Rebuild all
all: clean main
main: sum.o main.o
	mkdir -p build
	g++ -o build/main build/main.o build/sum.o

# Rebuild sum
sum.o:
	mkdir -p build
	g++ -c src/sum/sum.cpp -o build/sum.o

# Rebuild main
main.o:
	mkdir -p build
	g++ -c src/main.cpp -o build/main.o

# Clear builds
clear: clean
clean:
	rm -rf build
