/*
 * Simulated what was asked in the problem, but used path compression to move inside the
 * segments, in order to visit each index exactly once.
 */

#include <bits/stdc++.h>

const int N = 300005;
int a[N];
int next[N];

int getNext(int cur) {
  if (cur == next[cur])
    return cur;
  return next[cur] = getNext(next[cur]);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n + 1; ++i)
    next[i] = i;
  while (m--) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    int cur = getNext(l);
    while (cur <= r) {
      if (cur == x) {
        ++cur;
      } else {
        a[cur] = x;
        next[cur] = cur + 1;
      }
      cur = getNext(cur);
    }
  }
  for (int i = 1; i <= n; ++i)
    printf("%d%c", a[i], " \n"[i == n]);
}

