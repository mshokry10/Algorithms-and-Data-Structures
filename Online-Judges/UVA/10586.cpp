/*
 * Simulated a simplified version of long division, based on the divisor being
 * always (x^k + 1), liked that's illustrated in the pictures in the problem statement.
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 10004;

int c[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int n, k;
  while (scanf("%d %d", &n, &k) && n != -1 && k != -1) {
    memset(c, 0, sizeof c);
    for (int i = 0; i <= n; ++i) {
      scanf("%d", c + i);
    }
    for (int i = n; i >= k; --i) {
      c[i - k] -= c[i];
      c[i] = 0;
    }
    while (n > 0 && !c[n]) {
      --n;
    }
    for (int i = 0; i <= n; ++i) {
      printf("%d%c", c[i], " \n"[i == n]);
    }
  }
}

