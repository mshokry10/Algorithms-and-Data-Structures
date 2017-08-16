/*
 * There is an O(n^3) solution that's simply: for each pair of points, count all points that
 * lie on the same line of the pair of points. And this solution will pass within time too.
 *
 * However, this solution works in O(n^2 log n): We create a map, and for each pair of points
 * we use the slope and y-intercept of their line as a key, and increment the value by 1, and
 * maximize over all pairs.
 *
 * Note: We could have used a hash table to lower the complexity to only O(n^2).
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 707;

char buf[N];
int x[N], y[N];

void normalize(int &x, int &y) {
  int gcd = __gcd(x, y);
  x /= gcd;
  y /= gcd;
  if (y < 0) {
    x *= -1;
    y *= -1;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int t;
  scanf("%d\n\n", &t);
  bool space = false;
  while (t--) {
    int n = 0;
    while (fgets(buf, sizeof buf, stdin) != NULL && buf[0] != '\n') {
      sscanf(buf, "%d %d", x + n, y + n);
      ++n;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      map<pair<pair<int, int>, pair<int, int>>, int> cnt;
      for (int j = i + 1; j < n; ++j) {
        int m_num = y[i] - y[j];
        int m_den = x[i] - x[j];
        normalize(m_num, m_den);

        int b_num = y[i] * m_den - x[i] * m_num;
        int b_den = m_den;
        normalize(b_num, b_den);

        ++cnt[{{m_num, m_den}, {b_num, b_den}}];
      }
      for (auto x : cnt) {
        res = max(res, x.second + 1);
      }
    }
    if (space) {
      putchar('\n');
    }
    printf("%d\n", res);
    space = true;
  }
}

