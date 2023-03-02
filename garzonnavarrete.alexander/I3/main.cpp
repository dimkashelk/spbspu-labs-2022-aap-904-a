#include <iostream>
#include <string>

int main() {
  std::string input_str;
  std::string p, q;
  std::cout << "Enter a string: " << std::endl;
  getline(std::cin, input_str);
  std::cout << "Enter the first string (p): " << std::endl;
  getline(std::cin, p);
  std::cout << "Enter the second string (q): " << std::endl;
  getline(std::cin, q);

  std::string output_str = "";
  for (char c : input_str)
  {
    if (!isalpha(c) || !isascii(c))
    {
      output_str += c;
    }
  }
  std::cout << "Output string: " << output_str << std::endl;

  std::string combined_str = "";
  std::string::size_type i = 0, j = 0;
  while (i < p.length() && j < q.length())
  {
    combined_str += p[i];
    combined_str += q[j];
    i++;
    j++;
  }
  while (i < p.length())
  {
    combined_str += p[i];
    i++;
  }
  while (j < q.length())
  {
    combined_str += q[j];
    j++;
  }
  std::cout << "Combined string: " << combined_str << std::endl;

  return 0;
}
