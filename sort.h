#pragma once

#include <utility>
#include <vector>

namespace HackerRank {

// Insertion sort (inplace), stable
// Time complexity O(N^2) (worst/average)
// https://en.wikipedia.org/wiki/Insertion_sort
template <typename T>
void insertsort(std::vector<T>& ar);

// Quicksort (inplace), non-stable
// Implements Lomuto partition scheme
// https://en.wikipedia.org/wiki/Quicksort#Lomuto_partition_scheme
template <typename T>
void quicksort(std::vector<T>& v, int lo, int hi);


// Counting sort, stable
// Time complexity O(N)
// https://en.wikipedia.org/wiki/Counting_sort
// in - input vector,
// maxKey - max value what could be returned by key(T), min is 0
// key - function what return key in range 0..maxKey from T
// out - result sorted vector
template <typename T, typename Key>
void countingsort(const std::vector<T>& in, int maxKey, Key key,
		  std::vector<T>& out);

// Partially sorts vector 'v' and return kth element as if
// vector would be fully sorted
// inplace, time: average O(N), worst: O(n2)
// lo - lower bound of the vector
// hi - higher bound of the vector (not inclusive)
template <typename T>   
T kth(std::vector<T>& v, int k, int lo, int hi);

// Calculates median of the vector v
// Rearranges elements in v in such way that median will be in the middle of the array
// inplace, time: average O(N), worst: O(n2)  
template <typename T>
double median(std::vector<T> & v);

// Helper functions
namespace {

template <typename T>
void is_place(std::vector<T> & ar, int idx) {
  int x = ar.at(idx);
  while (idx != 0 and ar.at(idx-1) > x) {
    ar.at(idx) = ar.at(idx-1);
    --idx;
  }
  ar.at(idx) = x;
}

template <typename T>
int partition(std::vector<T>& v, int lo, int hi) {
  int pivot = v.at(hi-1);
  int i = lo;
  for (int j = lo; j < hi-1; ++j) {
    if (v.at(j) < pivot) {
	if (i != j) {
	  std::swap(v.at(j), v.at(i));
	}
	++i;
    }
  }
  std::swap(v.at(i), v.at(hi-1)); // swap pivot
  return i;
}
  
} // namespace anonymous
  
template <typename T>
void insertsort(std::vector<T>& ar) {
  for (int i = 1; i < ar.size(); ++i) {
    if (ar[i] < ar[i-1]) {
      is_place(ar, i);
    }
  }
}

template <typename T>  
void quicksort(std::vector<T>& v, int lo, int hi) {
  if (hi - lo <= 1) return;
  int p = partition(v, lo, hi);
  quicksort(v, lo, p);
  quicksort(v, p + 1, hi);
}

  
template <typename T>   
T kth(std::vector<T>& v, int k, int lo, int hi) {
  int p = partition(v, lo, hi);
  if (p == k) {
    return v[p];
  }
  if (p < k) {
    return kth(v, k, p + 1, hi);
  }
  return kth(v, k, lo, p);
}
  
template <typename T>
double median(std::vector<T> & v) {
  int sz = v.size();
  if (sz % 2 == 0) {
    return (kth(v, sz/2-1, 0, sz) + kth(v, sz/2, 0, sz)) / 2.0;
  }
  else {
    return kth(v, sz/2, 0, sz);
  }
}


template <typename T, typename Key>
void countingsort(const std::vector<T>& in, int maxKey, Key key,
		  std::vector<T>& out)
{
  std::vector<int> f(maxKey+1, 0);

  for (auto& x : in) {
    f[key(x)]++;
  }
  
  int total = 0;
  for (int i = 0; i <= maxKey; ++i) {
    int oldc = f[i];
    f[i] = total;
    total += oldc;
  }

  out.clear();
  out.resize(in.size());

  for (auto & x : in) {
    int pos = f[key(x)]++;
    out[pos] = x;
  }
}
 
} // namespace HackerRank
