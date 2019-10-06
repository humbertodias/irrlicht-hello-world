compile:
	g++ -g -I/usr/include/irrlicht main.cpp -o main -lIrrlicht

run:	compile
	./main
