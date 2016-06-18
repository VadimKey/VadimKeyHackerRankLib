#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

#include "fact.h"

using namespace std;
using namespace HackerRank;

bool testFact(string& reason) {
  auto mk_reason = [](int x, int res, int exp) -> string {
    return to_string(x) + "! = " + to_string(exp)
    + " but got " + to_string(res);
  };

  vector<uint64_t> nums = {0, 1, 2, 3,  4,      10,            15};
  vector<uint64_t> exps = {1, 1, 2, 6, 24, 3628800, 1307674368000};

  for (int i = 0; i < nums.size(); ++i) {
    uint64_t f = fact<uint64_t>(nums.at(i));
    if (f != exps.at(i)) {
      reason = mk_reason(i, f, exps.at(i));
      return false;
    }
  }

  return true;
}

bool testDecToFns(string& reason) {
  vector<uint64_t> in = { 0, 1, 2, 3, 463, 719, 720, 36288000 };
  vector<uint64_t> out =
    { 0, 0x10, 0x100, 0x110, 0x341010, 0x543210, 0x1000000, 0xA0000000000};

  for (int i = 0; i < in.size(); ++i) {
    uint64_t res = decToFns(in[i]);
    if (res != out[i]) {
      ostringstream o;
      o << "Expected decToFns(" << dec << in[i] << ") = "
	<< hex << out[i] << " but got: " << res;
      reason = o.str();
      return false;
    }
  }

  try {
    uint64_t max = numeric_limits<int64_t>::max();
    uint64_t res = decToFns(max);
    reason = "expected out_of_range exception wasn't thrown";
    return false;
  }
  catch (out_of_range& ex) {
  }
  
  return true;
}

int main() {
  string reason;
  if (not testFact(reason)) {
    cerr << "Test of fact() failed: " << reason << endl;
    return 1;
  }
  if (not testDecToFns(reason)) {
    cerr << "Test of decToFns() failed: " << reason << endl;
    return 1;
  }
  return 0;
}
