#include "CounterChanges.h"

int counterChanges(int prevVal, int current) {
  if ((prevVal > 0 && current < 0) || (prevVal < 0 && current > 0)) {
    return 1;
  } else {
    return 0;
  }
}
