#include "CheckingFirstTwoValues.h"

bool checkingFirstTwoValues(int prev, int current){
  if (prev > current && prev != 0) {
    return true;
  } else {
    return false;
  }
}
