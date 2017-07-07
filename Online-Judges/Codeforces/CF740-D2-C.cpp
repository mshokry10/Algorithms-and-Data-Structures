/*
 * Since the answer can't be greater than the minimum length of the subarrays (call
 * it len). Then we can construct an array that guarantees the answer to always be len
 * as follows: 0, 1, ..., len - 1, 0, 1, ..., len - 1, ...
 */
 
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  int len = INT_MAX;
  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    len = min(len, r - l + 1);
  }
  printf("%d\n", len);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", i % len, " \n"[i + 1 == n]);
  }
}

