g++ -c LinkedListAlgorithm.cpp -o LinkedListAlgorithm.o
ar r lib.a *.o

g++ main.cpp -o main.run lib.a
./main.run