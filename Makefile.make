CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

examheap: examheap.cpp heap.cpp heap.h
	$(CXX) $(CXXFLAGS) examheap.cpp heap.cpp -o examheap

clean:
	rm -f examheap *.o