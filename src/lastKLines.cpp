#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void printLastK(std::ifstream &inputStream, unsigned long K) {
  std::vector<std::string> lines(K);
  unsigned long index = -1;
  while (inputStream >> lines[++index % K]);
  index %= K;
  for (unsigned long i = 0; i < K; ++i) {
    // std::endl flushes after every line
    // using '\n' and calling .close at the end will flush only once
    // which is much faster
    std::cout << lines.at((i + index) % K) << "\n";
  }
}


int main(int argc, char *argv[]) {

  if (argc != 3) {
    std::cerr << "Usage: ./lastKLines inputFile K" << std::endl;
    return 1;
  }

  std::string inputFile = argv[1];
  std::ifstream inputStream(inputFile);

  if (!inputStream.is_open()) {
    std::cerr << "Unable to open file: " << inputFile << std::endl;
    return 1;
  }

  unsigned long K = strtoul(argv[2], nullptr, 0);

  if (K == 0) {
    std::cerr << "K = 0!" << std::endl;
    return 1;
  }

  printLastK(inputStream, K);

  inputStream.close();

  return 0;
}