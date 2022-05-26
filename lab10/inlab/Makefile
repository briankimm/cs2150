#Brian Kim, byk6q, 11/23/21, Makefile
# This is a comment

CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -Wall # Enable all warnings
DEBUG=-g

a.out: hNode.o huffmandec.o
	$(CXX) $(DEBUG) hNode.o huffmandec.o -o a.out

hNode.o: hNode.cpp hNode.h
huffmandec.o: huffmandec.cpp hNode.h

.PHONY: clean
clean:
	-rm -f *.o a.out
