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

} // namespace HackerRank

