/*
 * I fry as many burgers as possible on only one of their sides, and then I repeat the
 * process for the other side.
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  if (n <= m) {
    cout << 2 << endl;
    return 0;
  }
  int rows = n / m;
  int rem = n % m;
  cout << rows * 2 + !!rem + (rem * 2 > m) << endl;
}

