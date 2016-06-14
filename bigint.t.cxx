// Unit test for bigints
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "bigint.h"

using namespace std;

string to_string(const vector<char>& vec) {
  string res;
  for(auto it = vec.rbegin(); it != vec.rend(); ++it) {
    res += *it;
  }
  return res;
}

bool testX2(string & reason) {
  vector< vector<char> > tests = { {0}, {2}, {6,' '}, { 0, 1}, {9, 9, ' '} };
  vector< vector<char> >   res = { {0}, {4}, {2, 1}, { 0, 2}, {8, 9, 1} };

  assert(tests.size() == res.size());
  
  for (int i = 0; i < tests.size(); ++i) {
    reason = "Test " + to_string(tests.at(i)) + " ";

    int sz = tests.at(i).size();
    int l = tests.at(i).at(sz-1) == ' ' ? sz-1 : sz;
    int n = HackerRank::X2(&tests.at(i).at(0), l);
    if (n != res.at(i).size()) {
      reason = "Size mismatch. Expected: " + to_string(res.at(i).size())
	+ " Got: " + to_string(n);
      return false;
    }

    if (memcmp(&tests.at(i).at(0), &res.at(i).at(0), n) != 0) {
      reason = "failed. Expected: " + to_string(res.at(i))
	+ " Got: " + to_string(tests.at(i));
      return false;
    }
  }

  // python: for x in range(len(s1), 0, -1): print "%s," % s1[x-1],
  char bigint[] = {
    9, 8, 9, 7, 9, 6, 9, 5, 9, 4, 9, 3, 9, 2, 9, 1, 9, 8, 9, 7, 9, 6, 9, 5,
    9, 4, 9, 3, 9, 2, 9, 1, 9, 8, 9, 7, 9, 6, 9, 5, 9, 4, 9, 3, 9, 2, 9, 1, 9,' '};

  // python: s2 = str(int(s1)*2)
  // python: for x in range(len(s2), 0, -1): print "%s," % s2[x-1],
  char bigint_x2[] = {
    8, 7, 9, 5, 9, 3, 9, 1, 9, 9, 8, 7, 8, 5, 8, 3, 8, 7, 9, 5, 9, 3, 9, 1,
    9, 9, 8, 7, 8, 5, 8, 3, 8, 7, 9, 5, 9, 3, 9, 1, 9, 9, 8, 7, 8, 5, 8, 3, 8, 1
  };

  int n = HackerRank::X2(bigint, sizeof(bigint)-1);
  if (n != sizeof(bigint_x2) or memcmp(bigint, bigint_x2, n) != 0) {
    reason = "Big int X2 failed";
    return false;
  }
  
  return true;
}


bool testAdd(string & reason) {
  vector<string> numbers = { "32890328483243289084329",
			     "328490328432849038402384903",
			     "3890483209483290482309840239840923",
			     "2384903284903248320",
			     "0",
			     "394239423324234324"
  };

  // python:
  // nums = [ "32890328483243289084329",
  //     "328490328432849038402384903",
  //     "3890483209483290482309840239840923",
  //     "2384903284903248320",
  //     "0",
  //     "394239423324234324"]
  // sum = 0
  // for s in nums: sum += int(s)
  // print sum
  string res = "3890483538006512022784830158792799";

  string acc('0', 48);
  
  for (const string & s : numbers) {
    HackerRank::add(acc, s);
  }

  int i = 0;
  while(i < acc.size() and acc[i] == '0') {
    ++i;
  }

  if (res != acc.substr(i, string::npos)) {
    reason = "add() test failed: Result: " + acc.substr(i, string::npos)
      + ", Expected: " + res;
    return false;
  }
  
  return true;
}

bool test(string & reason) {
  return testX2(reason) and testAdd(reason);
}


int main() {
  string reason;
  if (not test(reason)) {
    cerr << "bigint tests are failed: " << reason << endl;
    return 1;
  }
  return 0;
}
