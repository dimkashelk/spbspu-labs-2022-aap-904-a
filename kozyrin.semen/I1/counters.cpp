#include <limits>
#include <stdexcept>
#include "counters.h"

bool overflow(int a, int b) {
  if (!b) {
    return a > std::numeric_limits< int >::max() - 1;
  }
  if (a < 0 && b < 0) {
    return a < std::numeric_limits< int >::min() - b;
  }
  if (a > 0 && b > 0) {
    return a > std::numeric_limits< int >::min() - b;
  }
  return true;
}

int sum(const int arr[]) {
  if (overflow(arr[0], arr[1])) {
    throw std::overflow_error("Values are too big/small. Why..?");
  }
  return arr[0] + arr[1];
}

void dividendCounter::operator()(int num) {
  if (prev && (num % prev == 0)) {
    if (overflow(cnt, 0)) {
      throw std::overflow_error("Too many inputs! You're cringe...\n");
    }
    cnt++;
  }
  prev = num;
}

void equalToSumCounter::operator()(int num) {
  if (prev[0] && sum(prev) == num) {
    if (overflow(cnt, 0)) {
      throw std::overflow_error("Too many inputs! You're cringe...\n");
    }
    cnt++;
  }
  prev[0] = prev[1];
  prev[1] = num;
}
