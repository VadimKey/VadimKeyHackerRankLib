#pragma once

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace HackerRank {

// Pascal triangle that can be used for calculation x choose y.
//
// In many HackerRank tasks the values stored in PascalTriangle
// could be very large, it this case they have to be stored
// by modulo (the second tepmplate parameter of this class)
template <typename IntType, IntType modulo = 1000000007ULL>
class PascalTriangle {
public:
  // throws std::invalid_argument if rows < 2
  PascalTriangle(int rows) : p(rows*2, std::vector<IntType>(rows*2))
  {
    if (rows < 2) {
      throw std::invalid_argument("The number of rows < 2");
    }
    build();
  }

  // O(N) = 1
  IntType choose(int k, int m) {
    if (k >= p.size() or m >= p.size()) {
      throw std::invalid_argument("Too big input values");
    }
    return p[k][m];
  }

  // prints the Pascal triangle to output stream
  void print(std::ostream& out, const PascalTriangle& t)
  {
    for (int i = 0; i < t.p.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
	out << t.p[i][j] << " ";
      }
      out << std::endl;
    }
  }

private:
  void build() {
    p[0][0] = 1;
    p[1][0] = 1;
    p[1][1] = 1;

    int n = p.size();
    
    for (int i = 2; i < n; ++i) {
      p[i][0] = 1;
      p[i][i] = 1;
      for (int j = 1; j < i; ++j) {
	p[i][j] = (p[i-1][j-1] % modulo + p[i-1][j] % modulo) % modulo;
      }
    }
  }
  
  std::vector< std::vector<IntType> > p;
};
 
} // namespace HackerRank
