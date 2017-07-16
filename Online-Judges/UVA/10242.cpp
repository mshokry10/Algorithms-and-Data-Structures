/*
 * I find the intersecting point between the two neighboring lines given, which
 * we will denote as (x3, y3). The other two points are (x1, y1) and (x2, y2).
 * And since the shape is a paralleogram, then we have two equalities:
 * (y3 - y1) / (x3 - x1) = (y2 - y) / (x2 - x) --> [1]
 * (y3 - y2) / (x3 - x2) = (y1 - y) / (x1 - x) --> [2]
 * Since we already know all variables in the first term in both [1] and [2],
 * then let's call them c1 and c2, respecively.
 * Now we have the two equalities:
 * c1 = (y2 - y) / (x2 - x)
 * c2 = (y1 - y) / (x1 - x)
 * By simple algebra, we can make them look like this:
 * c1 * x2 - c1 * x - y2 = -y --> [3]
 * c2 * x1 - c2 * x - y1 = -y --> [4]
 * By multiplying [4] by -1 then adding [3] and [4], then doing some algebra we get:
 * x = (y1 - y2 + c1 * x2 - c2 * x1) / (c1 - c2);
 * And by substitution in [4] we can calculate y.
 *
 * There is a special case here, which is when there's a vertical line, the slope will
 * be undefined. The trick is that I added EPSILON to the denominator so that it's not
 * really equal to 0, therefore it gives a result, that helps covering the special case.
 */
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-12;

struct Point {
  double x, y;
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
  bool operator!=(const Point &p) const {
    return !(*this == p);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  Point p[4];
  while (true) {
    int c = 0;
    for (int i = 0; i < 4; ++i) {
      c += scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    if (c != 8) {
      break;
    }

    for (int i = 0; i < 4; ++i) {
      for (int j = i + 1; j < 4; ++j) {
        if (p[i] == p[j]) {
          if (p[2] != p[i]) {
            swap(p[i], p[2]);
            if (p[3] != p[j]) {
              swap(p[j], p[3]);
            }
          }
          if (p[3] != p[j]) {
            swap(p[j], p[3]);
            if (p[2] != p[i]) {
              swap(p[2], p[i]);
            }
          }
          break;
        }
      }
    }
    double c1 = (p[2].y - p[0].y) / (p[2].x - p[0].x + EPS);
    double c2 = (p[2].y - p[1].y) / (p[2].x - p[1].x + EPS);
    double x = (p[0].y - p[1].y + c1 * p[1].x - c2 * p[0].x) / (c1 - c2 + EPS);
    double y = p[0].y - c2 * p[0].x + c2 * x;

    printf("%.3lf %.3lf\n", x, y);
  }
}

