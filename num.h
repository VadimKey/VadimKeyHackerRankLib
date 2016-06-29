#pragma once

#include <utility>

namespace HackerRank {
  // Greatest Common Divisor
  // Euclid algorithm
  int gcd(int a, int b) {
    if (a < b) {
      std::swap(a, b);
    }
    if (b == 0) return 0;

    int r = a % b;

    while (r != 0) {
      a = b; b = r;
      r = a % b;
    }
    return b;
  }

  // Least common multiple
  // Based on gcd() algorithm
  int lcm(int a, int b) {
    if (a > b) std::swap(a, b);
    if (a == 0) return 0;
    if (b % a == 0) {
      return b;
    }
    return a*b/gcd(b, a);
  }

} // namespace HackerRank
