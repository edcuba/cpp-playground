CXXFLAGS = -Wall -Wextra -std=c++17
CC = g++

all: randomwriter kbest mergesort

mergesort: mergeSort.cpp
	$(CC) $(CXXFLAGS) $^ -o $@

randomwriter: writeRandomNums.cpp
	$(CC) $(CXXFLAGS) $^ -o $@

kbest: kbest.cpp
	$(CC) $(CXXFLAGS) $^ -o $@

clean:
	rm -f randomwriter kbest mergesort
