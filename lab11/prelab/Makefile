#Brian Kim, byk6q, 11/30/21, Makefile
# This is a comment

CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -std=c++11

a.out:topological.o middleearth.o
	$(CXX) $(DEBUG) topological.o middleearth.o
	doxygen Doxyfile

topological.o: topological.cpp
middleearth.o: middleearth.cpp middleearth.h

.PHONY: clean
clean:
	-rm -f *.o a.out
