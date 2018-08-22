#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

template<class T>
std::vector<T>merge(const std::vector<T> &first, const std::vector<T> &second) {
  auto f = first.begin();
  auto s = second.begin();
  std::vector<T> result;
  while (f != first.end() || s != second.end()) {
    if (f == first.end()) {
      result.push_back(*s++);
    } else if (s == second.end() || *f < *s) {
      result.push_back(*f++);
    } else {
      result.push_back(*s++);
    }
  }
  return result;
}

template<class T>
std::vector<T> mergeSort(const typename std::vector<T>::const_iterator begin, const typename std::vector<T>::const_iterator end) {
  if (end - begin <= 1) {
    return std::vector<T>(begin, end);
  }
  auto middle = begin + std::distance(begin, end) / 2;
  auto left = mergeSort<T>(begin, middle);
  auto right = mergeSort<T>(middle, end);
  return merge<T>(left, right);
}

template<class T>
std::vector<T> readValues(std::ifstream &inputStream) {
  std::vector<T> data;
  std::istream_iterator<T> it(inputStream);
  std::copy(it, std::istream_iterator<T>(), std::back_inserter(data));
  return data;
}

int main(int argc, char *argv[]) {

if (argc != 2) {
    std::cerr << "Usage: ./mergesort inputFile" << std::endl;
    return 1;
  }

  std::string inputFile = argv[1];
  std::ifstream inputStream(inputFile);

  if (!inputStream.is_open()) {
    std::cerr << "Unable to open file: " << inputFile << std::endl;
    return 1;
  }

  auto data = readValues<int>(inputStream);
  auto sorted = mergeSort<int>(data.begin(), data.end());

  for (const auto &val: sorted) {
    std::cout << val << std::endl;
  }

  inputStream.close();
  return 0;
}