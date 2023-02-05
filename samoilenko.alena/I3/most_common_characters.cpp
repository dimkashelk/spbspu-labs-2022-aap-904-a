char* countMostCommonCharacters(char* destination, const char* source)
{
  unsigned int ascii[129] = {};
  int i = 0;
  while (source[i] != '\0')
  {
    ascii[int(source[i])]++;
    i++;
  }
  int idx1 = 128;
  int idx2 = 128;
  int idx3 = 128;
  for (i = 0; i < 128; i++)
  {
    if (ascii[i] > ascii[idx1])
    {
      idx3 = idx2;
      idx2 = idx1;
      idx1 = i;
    }
    else if (ascii[i] > ascii[idx2])
    {
      idx3 = idx2;
      idx2 = i;
    }
    else if (ascii[i] > ascii[idx3])
    {
      idx3 = i;
    }
  }
  destination[0] = char(idx1);
  destination[1] = char(idx2);
  destination[2] = char(idx3);
  int j;
  char tmp;
  char* ptr = &tmp;
  for (i=0; i < 3 -1; i++)
  {
    for (j = 0; j < 3 - i - 1; j++)
    {
      if(destination[j] > destination[j + 1])
      {
        ptr = destination;
        destination[j] = destination[j + 1];
        destination[j + 1] = tmp;
      }
    }
  }
  destination[3] = '\0';
  return destination;
}
