#pragma once

#include <vector>

namespace HackerRank {
  
// Implements sieve of Erathosthen algorithm
// for finding of prime numbers
template <typename IntType>
class Eratosthen {
public:
  // container of prime numbers
  std::vector<IntType> primes;

  // [1, max] is a range where search of primes will be performed.
  Eratosthen(size_t max) {
    eratosthen(max);
  }

private:
  std::vector<IntType> arr;

  void crossout(IntType p) {
    for (IntType i = 2*p; i < arr.size(); i += p) {
      arr[i] = 0;
    }
  }

  IntType nextprime(IntType p) {
    while (++p < arr.size() and arr[p] == 0) {
    }
    return p;
  }

  void eratosthen(size_t n) {
    arr.clear();
    arr.resize(n+1);
    for (int i = 0; i <= n; ++i) arr[i] = i;
    
    IntType p = 1;
    while ( (p = nextprime(p)) < arr.size() ) {
      primes.push_back(p);
      crossout(p);
    }
  }
};
 
} // namespace HackerRank
