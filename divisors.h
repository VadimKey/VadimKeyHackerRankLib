#pragma once

#include <cmath>
#include <vector>

#include "eratosthen.h"

namespace HackerRank {

template <typename IntType>
class Divisors {
public:
  // - maxPrimeDivisors specifies max prime number which will be using
  //    in divisors counting process
  // - cacheSize specifies for which max number sum of divisors will be cached
  Divisors(IntType maxPrimeDivisor, size_t cacheSize)
    : sieve(maxPrimeDivisor),
      cache(cacheSize)
  {  
  }

  // counts the number of divisors of the number 'n',
  // results may be incorrect if n > maxPrimeDivisor
  // for n = 0 result is undefined
  size_t count(IntType n) {
    if (n < 2) return 1;
    IntType N = n;
    IntType rootN = sqrt(N);

    size_t divisors = 1; // every number is divisible for one
    for (IntType p : sieve.primes) {
      if (p > N) break;
      
      size_t k = 0;
      while (n % p == 0) {
	++k;
	n /= p;
      }
      
      if (k != 0) {
	divisors *= (k+1);
      }
    }

    return divisors;
  }

  // Calculates the sum of divisors of the number 'x',
  // not including 'x' itself
  // Limitations:
  //   - for 0 will return 0
  //   - valid values range x > 0, for negative numbers the result is undefined
  //   - method doesn't check for overflow
  IntType sum(IntType x) {
    if (x <= 1) {
      return 0;
    }
    
    if (x < cache.size() and cache.at(x) != 0) {
      return cache.at(x);
    }
    
    IntType sum = 1; // every number if divisible to 1
    int rootx = sqrt(x);
    if (rootx * rootx == x) {
      sum += rootx;
    }
    else {
      ++rootx; // to calculate root x as divisor
    }
    
    for (int i = 2; i < rootx; ++i) {
      if (x % i == 0) {
	sum += i;
	sum += x/i;
      }
    }

    if (x < cache.size()) {
      cache.at(x) = sum;
    }
    
    return sum;
  }
  
private:
  Eratosthen<IntType> sieve;
  std::vector<IntType> cache;
};

} // namespace HackerRank
