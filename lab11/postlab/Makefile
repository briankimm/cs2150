#Brian Kim, byk6q, 12.3.21, Makefile
# This is a comment

CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -std=c++11

a.out:hashTable.o slidingpuzzle.o
	$(CXX) $(DEBUG) hashTable.o slidingpuzzle.o
	doxygen Doxyfile

hashTable.o: hashTable.cpp hashTable.h
slidingpuzzle.o: slidingpuzzle.cpp hashTable.h



.PHONY: clean
clean:
	-rm -f *.o a.out
