#include <utility>
#include <vector>
#include <iostream>

using namespace std;

int solve(vector<int>& v) {
  return 0;
}

int main() {
  int N;
  cin >> N;
  vector<int> vec;
  
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  cout << solve(vec) << endl;
  
  return 0;
}
