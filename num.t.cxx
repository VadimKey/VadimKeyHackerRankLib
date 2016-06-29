// Unit test for num.h
#define TESTHEADER "num.h"

#include "test/runner.h"

#include <map>

using namespace std;
using namespace HackerRank;

TEST(gcd) {
  map<int,pair<int,int>> in = {{0, {0,0}}, {0, {1, 0}}, {1, {2,3}},
			       {2, {2, 4}}, {2, {4,2}}, {10, {30, 100}}};

  for (auto& t : in) {
    int exp = t.first;
    auto inp = t.second;
    if (gcd(inp.first, inp.second) != exp) {
      reason = "gcd(" + to_string(inp.first) + ", " + to_string(inp.second)
	+ ") != " + to_string(exp);
      return false;      
    }
  }

  return true;
}


TEST(lcm) {
  map<int,pair<int,int>> in = {{0, {0,0}}, {0, {1, 0}}, {6, {2,3}},
			       {4, {2, 4}}, {4, {4,2}}, {300, {30, 100}}};

  for (auto& t : in) {
    int exp = t.first;
    auto inp = t.second;
    if (lcm(inp.first, inp.second) != exp) {
      reason = "lcm(" + to_string(inp.first) + ", " + to_string(inp.second)
	+ ") != " + to_string(exp);
      return false;      
    }
  }

  return true;
}



TEST_MAIN()
