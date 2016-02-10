// Exponentiation by Squaring
#include <bits/stdc++.h>

using namespace std;

// x^y mod m
// m = 0 means no mod
long long power(long long x, long long y, long long m = 0) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) {
      res *= x;
      if (m > 0)
        res %= m;
      --y;
    }
    x *= x;
    if (m > 0)
      x %= m;
    y >>= 1;
  }
  return res;
}

// Test
int main() {
  cout << power(2, 10) << endl;
}
