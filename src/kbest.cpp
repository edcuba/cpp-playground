
// read stream from a file and keep K largest numbers

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

template<class T>
std::vector<T> kbest(std::ifstream &inputStream, unsigned long K) {

  std::vector<T> best;
  T val;

  while (inputStream >> val) {
    best.push_back(val);
    std::push_heap(best.begin(), best.end(), std::greater<T>());
    if (best.size() == K) {
      std::pop_heap(best.begin(), best.end(), std::greater<T>());
      best.pop_back();
    }
  }

  return best;
}

int main(int argc, char *argv[]) {

  if (argc != 3) {
    std::cerr << "Usage: ./kbest inputFile K" << std::endl;
    return 1;
  }

  unsigned long K = strtoul(argv[2], nullptr, 0); // safety check

  std::string inputFile = argv[1];
  std::ifstream inputStream(inputFile); // safety check

  auto result = kbest<int>(inputStream, K);

  for (const auto &num: result) {
    std::cout << num << std::endl;
  }

  inputStream.close();

  return 0;
}