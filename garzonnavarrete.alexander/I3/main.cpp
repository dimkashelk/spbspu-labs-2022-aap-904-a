#include <iostream>
#include <string>

std::string removeNonAlphaASCII(std::string str) {
  std::string output_str = "";
  for (char c : str) {
    if (isalpha(c) && isascii(c)) {
      output_str += c;
    }
  }
  return output_str;
}

int main() {
  std::string input_str;
  std::cout << "Enter a string: " << std::endl;
  getline(std::cin, input_str);
  if (input_str.empty()) {
    std::cerr << "Error: Input strings cannot be empty" << std::endl;
    return 1;
  }

  std::string output_str = removeNonAlphaASCII(input_str);
  std::cout << "Output string: " << output_str << std::endl;

  std::string combined_str = "";
  size_t len = input_str.length();
  for (size_t i = 0; i < len; i++) {
    combined_str += input_str[i];
  }
  std::cout << "Combined string: " << combined_str << std::endl;
  return 0;
}
