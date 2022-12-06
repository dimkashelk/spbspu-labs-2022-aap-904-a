#include "counters.h"
#include <limits>
#include <stdexcept>

bool overflow(unsigned int cnt) {
  return cnt > std::numeric_limits< unsigned int >::max() - 1;
}

bool overflow(const int arr[]){
  if (arr[0] < 0 && arr[1] < 0) {
    return arr[0] < std::numeric_limits< int >::min() - arr[1];
  }
  if (arr[0] > 0 && arr[1] > 0) {
    return arr[0] > std::numeric_limits< int >::min() - arr[1];
  }
  return true;
}

int sum(const int arr[]) {
  if (overflow(arr)) {
    throw std::overflow_error("Values are too big/small. Why..?");
  }
  return arr[0] + arr[1];
}

void dividendCounter::operator()(int num) {
  if (prev && (num % prev == 0)) {
    if (overflow(cnt)) {
      throw std::overflow_error("Too many inputs! You're cringe...\n");
    }
    cnt++;
  }
  prev = num;
}

void equalToSumCounter::operator()(int num) {
  if (prev[0] && sum(prev) == num) {
    if (overflow(cnt)) {
      throw std::overflow_error("Too many inputs! You're cringe...\n");
    }
    cnt++;
  }
  prev[0] = prev[1];
  prev[1] = num;
}
