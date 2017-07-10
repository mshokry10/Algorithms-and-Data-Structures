#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 2; i < n; ++i) {
      cnt += min(i - 1, n - i);
    }
    printf("%d\n", cnt);
  }
}

