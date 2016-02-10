#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;
int lowestDivisor[MAX];

void sieve() {
  for (int i = 2; i * i <= MAX; i++) {
    if (lowestDivisor[i] == 0) {
      lowestDivisor[i] = i;
      for (int j = i * i; j <= MAX; j += i) {
        if (lowestDivisor[j] == 0)
          lowestDivisor[j] = i;
      }
    }
  }
}

map<int, int> factorize(int n) {
  map<int, int> res;
  while (n != 1) {
    res[lowestDivisor[n]]++;
    n /= lowestDivisor[n];
  }
  return res;
}

// Test
int main() {
  sieve();
  map<int, int> factors = factorize(12);
  for (auto factor : factors) {
    cout << factor.first << '^' << factor.second << endl;
  }
}
