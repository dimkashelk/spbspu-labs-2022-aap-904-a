#include "counters.h"
#include <limits>
#include <stdexcept>

int overflow(unsigned int cnt) {
  return cnt >= std::numeric_limits< int >::max() - 1;
}

int sum(int arr[]) {
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
