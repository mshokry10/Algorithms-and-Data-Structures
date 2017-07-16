/*
 * According to Fermat's last theorem, the equation a^n + b^n = c^n has no solutions
 * for n > 2. So we only need to worry about the cases 0, 1 and 2.
 * For 0, it's obviously not possible, and we can easily find the answer for 1 and 2.
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << ' ' << 2 << ' ' << 3 << endl;
  } else if (n == 2) {
    cout << 3 << ' ' << 4 << ' ' << 5 << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}

