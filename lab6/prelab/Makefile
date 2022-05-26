#Brian Kim, byk6q, 10/19/21, Makefile<prelab>
# This is a comment

CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -Wall # Enable all warnings
DEBUG=-g

a.out:hashTable.o timer.o wordPuzzle.o
	$(CXX) $(DEBUG) hashTable.o timer.o wordPuzzle.o -o a.out

hashTable.o: hashTable.cpp hashTable.h timer.h
timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h

.PHONY: clean
clean:
	-rm -f *.o a.out
