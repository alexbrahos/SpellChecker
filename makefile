runMe: main.o Table.o Node.o
	g++ main.o Table.o Node.o -o runMe
main.o: main.cpp Table.h Node.h TimeInterval.h
	g++ -c main.cpp
Table.o: Table.cpp Table.h Node.h
	g++ -c Table.cpp
Node.o: Node.cpp Node.h
	g++ -c Node.cpp
run: runMe
	./runMe
clean:
	rm *.o
	rm runMe
