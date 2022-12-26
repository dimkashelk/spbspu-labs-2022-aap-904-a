#ifndef LABS_MAKESTRING_HPP
#define LABS_MAKESTRING_HPP

#include <cstddef>
#include <istream>

char *makeString(char *destination, size_t &size, size_t &capacity, std::istream &input);

#endif //LABS_MAKESTRING_HPP
