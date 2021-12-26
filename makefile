all: compile connect run
compile:
	g++ -c -I "./include" ./src/Chain.cpp -o ./lib/Chain.o
	g++ -c -I "./include" ./src/PointChain.cpp -o ./lib/PointChain.o
	g++ -c -I "./include" ./src/AvlChain.cpp -o ./lib/AvlChain.o	
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
connect:
	g++ ./lib/Chain.o ./lib/PointChain.o ./lib/AvlChain.o ./lib/main.o -o ./bin/program
run:
	./bin/program