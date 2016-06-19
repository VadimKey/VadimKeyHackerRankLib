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
// - time: O(1)
// - space: constant O(1)
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

// Returns the value of given fns digit,
// where digit in the range from 0 to 15 (if digit out of range,
// std::out_of_range exception will be thrown
// The return value in the range from 0 to 0xF
// Complexity: O(1) time/space
uint64_t getFnsDigit(uint64_t fns, int digit) {
  if (digit < 0 or digit > 0xF)
    throw std::out_of_range("Digit " + std::to_string(digit) + " is out of range");
  uint64_t res = fns >> (digit * 4);
  return (res & 0xF);
}

  
} // namespace HackerRank

