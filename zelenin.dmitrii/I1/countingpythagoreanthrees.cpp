#include "countingpythagoreanthrees.h"

void countingPythagoreanThrees(int& value, int& program_launch_number, int& count_of_pythagorean_threes, int& x, int& y, int& z)
{
  if (program_launch_number == 3)
  {
    program_launch_number = 0;
  }
  if (program_launch_number == 0)
  {
    x = value;
  }
  if (program_launch_number == 1)
  {
    y = value;
  }
  if (program_launch_number == 2)
  {
    z = value;
  }
  if (((x * x + y * y == z * z) || (x * x + z * z == y * y) || (z * z + y * y == x * x)) && (x != 0) && (y != 0) && (z != 0))
  {
    count_of_pythagorean_threes += 1;
  }
}
