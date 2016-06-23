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


bool checkCounting(const string& name, const vector<int>& v, const vector<int>& vs, string& reason) {
  vector<int> out;
  countingsort(v, 10, [](int x) { return x; }, out);
  if (out != vs) {
    reason = name + " failed";
    return false;
  }
  return true;
}


bool testCountingsort(string& reason) {
  vector<int> v1 = {1, 2, 3};
  if (not checkCounting("test1", v1, {1, 2, 3}, reason)) return false;

  vector<int> v2 = {1};
  if (not checkCounting("test2", v2, {1}, reason)) return false;
  
  vector<int> v3 = {};
  if (not checkCounting("test3", v3, {}, reason)) return false;

  vector<int> v4 = {4, 3, 2, 1};
  if (not checkCounting("test4", v4, {1,2,3,4}, reason)) return false;  

  vector<int> v5 = {4, 3, 5, 2, 6, 1};
  if (not checkCounting("test5", v5, {1,2,3,4,5,6}, reason)) return false;  

  vector<int> v6 = {2, 4, 3, 5, 3, 2, 6, 1};
  if (not checkCounting("test6", v6, {1,2,2,3,3,4,5,6}, reason)) return false;  

  // sort strings by their length
  vector<string> v7 = {"epsilon", "alfa", "beta", "thetta" };
  vector<string> v7e =  {"alfa", "beta", "thetta", "epsilon" };
  vector<string> out;
  countingsort(v7, 10, [](const string& x) { return x.size(); }, out);
  if (out != v7e) {
    reason = "v7 is failed";
    return false;
  }
  
  return true;
}

bool testKth(string& reason) {
  try {
    vector<int> empty;
    int x = kth(empty, 0, 0, 0);
    reason = "Expected exception out of range wasn't thrown";
    return false;
  } catch(out_of_range& ex) {
    // pass
  }

  {
    vector<double> one = {1};
    int x = kth(one, 0, 0, 1);
    if (x != 1) {
      return "kth(one, 0, 0, 1)";
      return false;
    }
  }

  {
    vector<double> five = {1, 5, 4, 2, 3};
    int x = kth(five, 3, 0, 5);
    if (x != 3) {
      return "kth(fice, 3, 0, 5)";
      return false;
    }
  }

  {
    vector<double> dups = {1, 5, 2, 2, 2};
    int x = kth(dups, 3, 0, 5);
    if (x != 2) {
      return "kth(dups, 3, 0, 5)";
      return false;
    }
  }
  
  return true;
}

bool tesMedian(string& reason) {
  try {
    vector<int> empty;
    double x = median(empty);
    reason = "Expected exception out of range wasn't thrown";
    return false;
  } catch(out_of_range& ex) {
    // pass
  }

  {
    vector<double> one = {1};
    double x = median(one);
    if (x != 1) {
      return "median(one)";
      return false;
    }
  }

  {
    vector<int16_t> odd = {1, 5, 4, 2, 3};
    double x = median(odd);
    if (x != 3) {
      return "median(odd)";
      return false;
    }
  }

  {
    vector<int16_t> even = {1, 2, 3, 4};
    double x = median(even);
    if (x != 1.5) {
      return "median(even)";
      return false;
    }
  }
  
  {
    vector<double> dups = {1, 5, 2, 2, 2};
    int x = median(dups);
    if (x != 2) {
      return "median(dups)";
      return false;
    }
  }
  
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

  if (not testCountingsort(reason)) {
    cerr << "Test countingsort() failed: " << reason << endl;
    return 1;
  }

  if (not testKth(reason)) {
    cerr << "Test kth() failed: " << reason << endl;
    return 1;
  }

  if (not tesMedian(reason)) {
    cerr << "Test meadian() failed: " << reason << endl;
    return 1;
  }
  
  return 0;
}
