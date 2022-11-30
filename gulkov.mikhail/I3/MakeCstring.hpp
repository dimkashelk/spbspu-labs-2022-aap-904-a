#ifndef MAKECSTRING_HPP
#define MAKECSTRING_HPP

#include <cstddef>
#include <istream>

char *make_cstring(char *cstring, unsigned int &size, unsigned int &capacity, std::istream &input);

#endif
