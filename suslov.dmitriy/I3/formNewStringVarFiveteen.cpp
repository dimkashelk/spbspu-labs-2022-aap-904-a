#include "formNewStringVarFiveteen.h"
char *varFiveteenFunction(char *destination, const char *source_1, const char *source_2)
{
  int c = 0;
  int i = 0;
  while (source_1[i] != '\0')
  {
    int j = 0;
    while (source_2[j] != '\0' and source_2[j] != source_1[i])
    {
      j++;
    }
    if (source_2[j] != source_1[i])
    {
      destination[c] = source_1[i];
      c++;
    }
    i++;
  }
  destination[c] = '\0';
  return destination;
}
