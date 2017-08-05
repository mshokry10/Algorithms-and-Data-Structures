#include <bits/stdc++.h>

using namespace std;

const int N = 111;

int a[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  int i = 0, j = n - 1, cur = 1;
  while (true) {
    a[i][j] = cur++;
    if (i == n - 1 && j == 0) {
      break;
    }
    if (i < n - 1 && j < n - 1) {
      ++i;
      ++j;
    } else if (j == n - 1) {
      j = n - 1 - i - 1;
      i = abs(min(0, j));
      j = max(0, j);
    } else if (i == n - 1) {
      i = n - 1 - j + 1;
      j = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d%c", a[i][j], " \n"[j + 1 == n]);
    }
  }
}

