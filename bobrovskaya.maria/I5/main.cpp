#include <iostream>
#include <CreateCString.h>
#include "isExpression.h"
int main()
{
 char* cstring = nullptr;
 try
 {
   cstring = createCString(std::cin);
 }
 catch(const std::exception& e){
   std::cerr << e.what() << "\n";
   delete[] cstring;
   return 1;
 }
 std::cout << std::boolalpha << isExpression(cstring) << '/n';
 delete[] cstring;
 return 0;
}

