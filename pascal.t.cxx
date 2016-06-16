#include <iostream>

#include "pascal.h"
#include "fact.h"

using namespace std;
using namespace HackerRank;

uint64_t choose(int n, int k) {
  return fact<uint64_t>(n) / (fact<uint64_t>(k) * fact<uint64_t>(n - k));
}

bool testPascalTriangle(string& reason)
try {
  PascalTriangle<uint64_t> p(1001);

  if (p.choose(1, 1) != choose(1, 1)) {
    reason = "choose(1, 1) failed";
    return false;
  }

  if (p.choose(3, 2) != choose(3, 2)) {
    reason = "choose(3, 2) failed";
    return false;
  }

  // https://www.wolframalpha.com/input/?i=15+choose+7
  if (p.choose(15, 7) != 6435) {
    reason = "choose(15, 7) failed";
    return false;
  }

  // 1000 choose 7 = 194280608456793000
  // by modulo 1000000007 result will be: 96828751
  if (p.choose(1000, 7) != 96828751ULL) {
    reason = "choose(1000, 7) failed";
    return false;
  }
  
  return true;
  
} catch(std::exception& ex) {
  reason = ex.what();
  return false;
}

int main() {
  string reason;
  if (not testPascalTriangle(reason)) {
    cerr << "Test PascalTriangle failed: " << reason << endl;
    return 1;
  }
  return 0;
}
