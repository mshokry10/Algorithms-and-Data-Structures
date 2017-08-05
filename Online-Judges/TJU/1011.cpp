/*
 * We use cross product to calculate the area of the polygon, by fixing a point as the start
 * point of both vectors and iterating over i, and i + 1, the end points of the vectors.
 * And for the points on the edges, for each line we can find the number of lattice points on
 * it with the formula gcd(x, y) - 1.
 */
#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

struct Vector {
  Point a, b;
  Vector(Point a, Point b) {
    this->a = a;
    this->b = b;
  }
  Point normalize() {
    return Point(b.x - a.x, b.y - a.y);
  }
};

int cross(Vector ab, Vector cd) {
  int x1 = ab.normalize().x;
  int y1 = ab.normalize().y;
  int x2 = cd.normalize().x;
  int y2 = cd.normalize().y;
  return x1 * y2 - x2 * y1;
}

int pointsOnLine(Point a, Point b) {
  return __gcd(abs(a.x - b.x), abs(a.y - b.y)) - 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int t, tst = 1;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<Point> points;
    Point cur(0, 0);
    for (int i = 0; i < n; ++i) {
      int dx, dy;
      scanf("%d %d", &dx, &dy);
      cur.x += dx;
      cur.y += dy;
      points.push_back(cur);
    }
    int A = 0;
    for (int i = 1; i + 1 < n; ++i) {
      A += cross(Vector(points[0], points[i]), Vector(points[0], points[i + 1]));
    }
    int E = n;
    for (int i = 0; i < n; ++i) {
      E += pointsOnLine(points[i], points[(i + 1) % n]);
    }
    int I = (A - E + 2) / 2;
    printf("Scenario #%d:\n%d %d %.1lf\n\n", tst, I, E, abs(A) / 2.0);
    ++tst;
  }
}

