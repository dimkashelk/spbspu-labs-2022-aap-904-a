#include "CounterChanges.h"

int counterChanges(int prev, int current) {
  if ((prev > 0 && current < 0) || (prev < 0 && current > 0)) {
    return 1;
  } else {
    return 0;
  }
}
