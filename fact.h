#pragma once

namespace HackerRank {

// Iterative method for factorials calculations
// Doesn't check for overflow
// 20! is the max number representable by uint64_t
template <typename Int>
Int fact(int N) {
  Int res = 1;
  int i = 2;
  while (i <= N) {
    res = (res * i);
    ++i;
  }
  return res;
}

// Converts the number from decimal to factorial
// number system.
// https://en.wikipedia.org/wiki/Factorial_number_system
// Limitations:
//   as we can store only 16 hex digits in uint64_t
//   so max representable number is 16!
//   if v can't be represented in factorial number system
//   exception out of range will be thrown.
// Complexity:
// - time:
// - space: constant
uint64_t decToFns(uint64_t v) {
  uint64_t res = 0;
  int pos = 1;
  while (v != 0 and pos <= 16) {
    uint64_t r = v % pos;
    v /= pos;
    res |= r << ((pos-1) * 4);
    ++pos;
  }
  if (v != 0) {
    throw std::out_of_range(std::to_string(v) + " is too big");
  }
  return res;
}
 
} // namespace HackerRank

