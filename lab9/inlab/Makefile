#Brian Kim, byk6q, 11/16/21
# This is a comment

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

a.out: linkedlist.o
	$(CXX) $(DEBUG) linkedlist.o -o a.out

linkedlist.o: linkedlist.c


.PHONY: clean
clean:
	-rm -f *.o a.out
