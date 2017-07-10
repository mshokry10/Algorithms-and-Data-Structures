/*
 * Sorted the angles according to their angles with the top of the positive part of the
 * x-axis, and connected each consecutive 2 points, to make sure there's nothing between them.
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 10004;

pair<double, int> a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    a[i].first = atan(1.0 * abs(y) / abs(x));
    a[i].second = i + 1;
    if (x < 0 && y >= 0) {
      a[i].first = 180 - a[i].first;
    } else if (x < 0 && y < 0) {
      a[i].first = 270 - (90 - a[i].first);
    } else if (x >= 0 && y < 0) {
      a[i].first = 360 - a[i].first;
    }
  }
  sort(a, a + n);
  for (int i = 0; i < n; i += 2) {
    printf("%d %d\n", a[i].second, a[i + 1].second);
  }
}

