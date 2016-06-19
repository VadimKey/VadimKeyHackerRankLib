#include <sstream>
#include <string>

#include "utils.h"

using namespace std;
using namespace HackerRank;

bool check(ostringstream& oss, string exp, string& reason) {
  if (oss.str() != exp) {
    reason = "output is " + oss.str() + " expected: " + exp;
    return false;
  }
  return true;
}

bool testPv(string& reason) {
  vector<int> v = {1, 2, 3};
  
  ostringstream oss1;
  pv(oss1, v);
  if (not check(oss1, "1 2 3\n", reason)) return false;

  ostringstream oss2;
  pv(oss2, v, 0, 2);
  if (not check(oss2, "1 2\n", reason)) return false;

  ostringstream oss3;
  pv(oss3, v, 1, 1);
  if (not check(oss3, "", reason)) return false;
  
  return true;
}

int main() {
  string reason;
  if (not testPv(reason)) {
    cerr << "Test pv() failed: " << reason << endl;
    return 1;
  }
  return 0;
}
