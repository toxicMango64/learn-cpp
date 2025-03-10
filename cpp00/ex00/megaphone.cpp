#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

namespace utils {
  void touppercase(std::string &str) {
    for (std::string::size_type i = 0; i < str.size(); ++i) {
      str[i] = std::toupper(str[i]);
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 1;
  }

  for (int i = 1; i < argc; ++i) {
    try {
      std::string arg = argv[i];
      utils::touppercase(arg);
      std::cout << arg << " ";
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
      return 1;
    }
  }
  std::cout << std::endl;

  return 0;
}