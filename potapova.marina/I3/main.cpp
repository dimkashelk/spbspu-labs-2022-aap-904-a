#include <iostream>
#include "newstring.h"

int main()
  char * cstring = nullptr;
  try ()
  {
    cstring = potapova::receiveStringTypeC(std::cin);
  }
  catch(const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
}
