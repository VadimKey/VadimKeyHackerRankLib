#pragma once

#include <iostream>
#include <vector>

namespace HackerRank {

// print vector in single line from lo to hi (where hi isn't included)
// to output stream.
// if hi == 0, vector size used as hi value.
// if lo >= hi nothing printed.
// each value of vector is separated by space
// end line is added after the last element.
template <typename T>
void pv(std::ostream& out, const std::vector<T>& v, int lo = 0, int hi = 0) {
  if (lo == 0 and hi == 0) hi = v.size();
  if (lo >= hi) return;

  for (int i = lo; i < hi; ++i) {
    if (i != lo) out << " ";
    out << v[i];    
  }
  out << std::endl;
}

} // namespace HackerRank
