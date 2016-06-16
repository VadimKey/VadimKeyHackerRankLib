#include <iostream>
#include <string>
#include <vector>
#include "divisors.h"

using namespace HackerRank;
using namespace std;

bool testCount(string& reason) {
  Divisors<uint64_t> divs{997, 0};

  try {
    divs.count(0);
  }
  catch (...) {
    reason = "divs.count(0) throws an unexpected exception.";
    return false;
  }

  vector<uint64_t> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 107, 111, 1000};
  // use https://www.wolframalpha.com/input/?i=divisors+4
  vector<uint64_t> cnts = {1, 2, 2, 3, 2, 4, 2, 4, 3,  4,  3,   2,   4,   16};

  for (int i = 0; i < nums.size(); ++i) {
    uint64_t res = divs.count(nums.at(i));
    if (res != cnts.at(i)) {
      reason = "Expected number of divisors of " + to_string(nums.at(i))
	+ " is " + to_string(cnts.at(i)) + " but result of count() is "
	+ to_string(res);
      return false;
    }
  }
  
  return true;
}

bool testSum(string& reason) {
  Divisors<uint64_t> divs{0, 100000};  

  if (divs.sum(0) != 0) {
    reason = "divs.sum(0) doesn't equal to 0";
    return false;
  }

  if (divs.sum(1) != 0) {
    reason = "divs.sum(1) doesn't equal to 0";
    return false;
  }

  vector<uint64_t> nums = {2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 107, 111, 1000};
  // to get sum use https://www.wolframalpha.com/input/?i=sum+of+divisors+2
  // but subtract the number itself
  vector<uint64_t> sums = {1, 1, 3, 1, 6, 1, 7, 4,  8,  6,   1,  41, 1340};

  for (int i = 0; i < nums.size(); ++i) {
    uint64_t res = divs.sum(nums.at(i));
    if (res != sums.at(i)) {
      reason = "Expected sum of divisors of " + to_string(nums.at(i))
	+ " is " + to_string(sums.at(i)) + " but result of sum() is "
	+ to_string(res);
      return false;
    }
  }
  
  return true;
}

bool test(string& reason) {
  if (not testCount(reason)) return false;
  if (not testSum(reason)) return false;
  return true;
}

int main() {
  string reason;
  if (not test(reason)) {
    cerr << "Test Divisors failed: " << reason << endl;
    return 1;
  }

  return 0;
}
