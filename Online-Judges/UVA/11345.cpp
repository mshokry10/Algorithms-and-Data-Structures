#include <bits/stdc++.h>

using namespace std;

const int MAX = 10004;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int t, tst = 1;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int l = -MAX, r = MAX, u = MAX, d = -MAX;
    while (n--) {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      l = max(l, x1);
      r = min(r, x2);
      u = min(u, y2);
      d = max(d, y1);
    }
    printf("Case %d: %d\n", tst, max(0, r - l) * max(0, u - d));
    ++tst;
  }
}

