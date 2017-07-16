/*
 * Try all permutations in which all players have positive power using dp with bitmasks.
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 11;

int memo[(1 << N) + 7];
int p[N][N];

int solve(int mask) {
  int i = __builtin_popcount(mask);
  if (i == N) {
    return 0;
  }
  int &ret = memo[mask];
  if (ret != -1) {
    return ret;
  }
  ret = -1e9;
  for (int j = 0; j < N; ++j) {
    if (!((mask >> j) & 1) && p[j][i]) {
      ret = max(ret, solve(mask | (1 << j)) + p[j][i]);
    }
  }
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        scanf("%d", &p[i][j]);
      }
    }
    memset(memo, -1, sizeof memo);
    printf("%d\n", solve(0));
  }
}

