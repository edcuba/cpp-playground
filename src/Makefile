CXXFLAGS = -Wall -Wextra -std=c++17 -O3
CC = g++

all: randomwriter kbest mergesort lastklines

mergesort: mergeSort.cpp
	$(CC) $(CXXFLAGS) $^ -o $@

randomwriter: writeRandomNums.cpp
	$(CC) $(CXXFLAGS) $^ -o $@

kbest: kbest.cpp
	$(CC) $(CXXFLAGS) $^ -o $@

lastklines: lastKLines.cpp
	$(CC) $(CXXFLAGS) $^ -o $@

clean:
	rm -f randomwriter kbest mergesort lastklines
