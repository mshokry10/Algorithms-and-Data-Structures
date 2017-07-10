#include <bits/stdc++.h>

using namespace std;

const int N = 111;

char s[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int t;
  scanf("%d\n\n", &t);
  bool empty_line = false;
  while (t--) {
    if (empty_line) {
      putchar('\n');
    }
    empty_line = true;
    int x, y;
    scanf("%d %d\n", &x, &y);
    double distance = 0;
    while (gets(s) && s[0]) {
      int x[2], y[2];
      sscanf(s, "%d %d %d %d", x, y, x + 1, y + 1);
      s[0] = 0;
      distance += hypot(1.0 * x[0] - x[1], 1.0 * y[0] - y[1]);
    }

    int hours = floor(distance / 10000);
    int minutes = round(fmod(60 * distance / 10000, 60));
    hours += minutes / 60;
    minutes %= 60;
    printf("%d:%02d\n", hours, minutes);
  }
}

