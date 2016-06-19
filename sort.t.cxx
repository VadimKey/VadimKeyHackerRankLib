#include <iostream>
#include <string>
#include <vector>

#include "sort.h"

using namespace std;
using namespace HackerRank;

bool check(const string& name, vector<int>& v, const vector<int>& vs, string& reason,
	   std::function<void(vector<int>&)> sorter) {
  sorter(v);
  if (v != vs) {
    reason = name + " failed";
    return false;
  }
  return true;
}

bool testSort(string& reason, std::function<void(vector<int>&)> f) {
  vector<int> v1 = {1, 2, 3};
  if (not check("test1", v1, {1, 2, 3}, reason, f)) return false;

  vector<int> v2 = {1};
  if (not check("test2", v2, {1}, reason, f)) return false;
  
  vector<int> v3 = {};
  if (not check("test3", v3, {}, reason, f)) return false;

  vector<int> v4 = {4, 3, 2, 1};
  if (not check("test4", v4, {1,2,3,4}, reason, f)) return false;  

  vector<int> v5 = {4, 3, 5, 2, 6, 1};
  if (not check("test5", v5, {1,2,3,4,5,6}, reason, f)) return false;  

  vector<int> v6 = {2, 4, 3, 5, 3, 2, 6, 1};
  if (not check("test6", v6, {1,2,2,3,3,4,5,6}, reason, f)) return false;  
  
  return true;
}

int main() {
  string reason;
  std::function<void(vector<int>&)> insert = [](vector<int>& v){ insertsort(v); };
  if (not testSort(reason, insert)) {
    cerr << "Test insertsort() failed: " << reason << endl;
    return 1;
  }

  std::function<void(vector<int>&)> quick = [](vector<int>& v){ quicksort(v, 0, v.size()); };
  if (not testSort(reason, quick)) {
    cerr << "Test quicksort() failed: " << reason << endl;
    return 1;
  }

  return 0;
}
