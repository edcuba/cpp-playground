#include <fstream>
#include <string>
#include <iostream>
#include <random>
#include <cstdlib>

int main(int argc, char** argv) {

  if (argc != 3 && argc != 4) {
    std::cerr << "Usage: ./randomwriter target amount [max]" << std::endl;
    return 1;
  }

  std::string targetName = argv[1];

  unsigned long amount = strtoul(argv[2], nullptr, 0);

  unsigned long max = INT_MAX;

  if (argc == 4) {
    max = strtoul(argv[3], nullptr, 0);
    if (max < 1) {
      std::cerr << "Max must be > 0" << std::endl;
      return 1;
    }
  }

  if (amount < 1) {
    std::cerr << "Amount must be positive" << std::endl;
    return 1;
  }

  std::ofstream target(targetName);

  if (!target.is_open()) {
    std::cerr << "Failed to open file: " + targetName << std::endl;
    return 1;
  }

  std::default_random_engine generator;
  std::uniform_int_distribution<unsigned long> distribution(0, max);

  while (amount--) {
    target << distribution(generator) << std::endl;
  }

  target.close();
  return 0;
}