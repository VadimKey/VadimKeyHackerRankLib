#include <iostream>
#include <string>

#include "abundant.h"

using namespace std;

bool test(string& reason) {
  HackerRank::Abundant abundant;

  if (abundant.numbers.count(0)) {
    reason = "0 isn't abundant";
    return 0;
  }

  if (abundant.isAbundant(0)) {
    reason = "0 isn't abundant";
    return 0;
  }
  
  int seq[] = {
    12, 18, 20, 24, 30, 36, 40, 42, 48, 54, 56,
    60, 66, 70, 72, 78, 80, 84, 88, 90, 96, 100,
    102, 104, 108, 112, 114, 120
  };
  
  for (int s : seq) {
    if (abundant.numbers.count(s) == 0) {
      reason = "seq test failed with " + to_string(s);
      return false;
    }
  }

  if (abundant.numbers.count(945) == 0) {
    reason = "945 is abundant";
    return false;
  }

  // 28 is a perfect number (the number = sum of divisors itself)
  if (abundant.numbers.count(28) == 1) {
    reason = "28 is not abundant";
    return false;
  }

  if (abundant.isAbundant(12345)) {
    reason = "12345 is not an abundant";
    return false;
  }

  if (not abundant.isAbundant(222222)) {
    reason = "222222 is abundant number";
  }

  return true;
}

int main() {
  string reason;
  if (not test(reason)) {
    cerr << "Abundant test failed: " << reason << endl;
    return 1;
  }
  
  return 0;
}
