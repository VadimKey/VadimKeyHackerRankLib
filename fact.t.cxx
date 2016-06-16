#include <iostream>
#include <string>
#include <vector>

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

int main() {
  string reason;
  if (not testFact(reason)) {
    cerr << "Test of fact() failed: " << reason << endl;
    return 1;
  }
  return 0;
}
