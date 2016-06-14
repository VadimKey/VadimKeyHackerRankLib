#pragma once

#include <cmath>
#include <unordered_set>

namespace HackerRank {

// https://en.wikipedia.org/wiki/Abundant_number
// https://www.hackerrank.com/contests/projecteuler/challenges/euler023
class Abundant {
public:  
  Abundant() {
    fill();
  }

  std::unordered_set<int> numbers; // keeps abundant numbers from 12 to 100'000

  bool isAbundant(int x) {
    int sum = 1; // every number if divisible to 1
    int rootx = sqrt(x);
    
    if (rootx * rootx == x) {
      sum += rootx;
    }
    else {
      ++rootx; // to include the rootx to for loop range
    }
    
    for (int i = 2; i < rootx; ++i) {
      if (x % i == 0) {
	sum += i;
	sum += x/i;
	if (sum > x) return true;
      }
    }
    return false;
  }

private:

  void fill() {
    // The smallest abundant number not divisible by 2 or by 3 is 5391411025
    // and our range is from 1 to 10e5
    for (int i = 12; i < 945; i += 2) {
      if (isAbundant(i)) {
	numbers.insert(i);
      }
    }

    // The smallest odd abundant number is 945
    for (int i = 945; i <= 100000; ++i) {
      if (i % 3 == 0 or i % 2 == 0) {
	if (isAbundant(i)) {
	  numbers.insert(i);
	}
      }
    }
  }
};

} // namespace HackerRunk
