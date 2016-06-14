#pragma once

/* Library of functions for working with big integers */

#include <string>

namespace HackerRank {

// doubles the number represented as array of digits,
// returns the new size of the buffer (if carry over happened)
// only positive numbers are allowed
// acc[0] stores the less significant digit
int X2(char * acc, int sz);

// add the number from S represented as strings ("12345")
// to accumulator ('acc')
void add(std::string& acc, const std::string& s,
	 int digit = 0, int co = 0);



// Implementation is below
 
// doubles the number in the acc
// each element in acc has a number 0,1,2,3
// not char '0', '1', '2'...
// see euler/16.cxx
int X2(char * acc, int sz) {
  int co = 0;
  for (int digit = 0; digit < sz; ++digit) {
    int s2 = acc[digit];
    int sum = (s2 << 1) + co;
    acc[digit] = sum % 10;
    co = sum / 10;
  }
  
  if (co) {
    acc[sz] = 1;
    return sz + 1;
  }
  return sz;
}

namespace {
  using namespace std;
  
  
  void addcarry(string& acc, int digit) {
    if (digit == acc.size()) {
      acc = "1" + acc;
      return;
    }
    int ai = acc.size() - digit - 1;
    int s1 = acc[ai] - '0';
    int sum = s1 + 1;
    acc[ai] = '0' + sum % 10;
    if (sum / 10 != 0) {
      addcarry(acc, digit + 1);
    }
  }
} // namespace {}

  
void add(std::string& acc, const std::string& s,
	 int digit, int co)
{
  if (digit == s.size()) {
    if (co != 0) {
      addcarry(acc, digit);
    }
    return;
  }
  
  int si = s.size() - digit - 1;
  int ai = acc.size() - digit - 1;
  int s1 = acc[ai] - '0';
  int s2 = s[si] - '0';
  int sum = s1 + s2 + co;
  acc[ai] = '0' + sum % 10;
  add(acc, s, digit+1, sum / 10);
}
  
} // namespace HackerRank
