/*
 * A recursive implementation to the encoding method described in the problem statement.
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 20004;

char s[N], res[N];
int k = 0;

void solve(int x, int y) {
  if (x > y) {
    return;
  }
  int n = y - x + 1;
  int mid = (n + 1) / 2 - 1;
  res[x + mid] = s[k++];
  solve(x, x + mid - 1);
  solve(x + mid + 1, y);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  scanf("%[^\n]\n", s);
  int n = strlen(s);
  solve(0, n - 1);
  puts(res);
}

