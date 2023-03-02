#include "counterpythagoreanthrees.h"

void counterPythagoreanThrees(int& value, int& program_launch_number, int& count_of_pythagorean_threes, int& x, int& y, int& z)
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
  if (x && y && z)
  {
    if (isPyth(x, y, z) == 1)
    {
      count_of_pythagorean_threes += 1;
    }
    if (isPyth(x, z, y) == 1)
    {
      count_of_pythagorean_threes += 1;
    }
    if (isPyth(z, y, x) == 1)
    {
      count_of_pythagorean_threes += 1;
    }
  }
}
