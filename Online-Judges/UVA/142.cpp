#include <bits/stdc++.h>

using namespace std;

const int N = 55, INF = 2e9;

struct {
  int x, y;
  bool visible;
} items[N];

struct {
  int x1, y1, x2, y2;
} regions[N];

bool isInsideRegion(int x, int y, int i) {
  return regions[i].x1 <= x && x <= regions[i].x2 &&
      regions[i].y1 <= y && y <= regions[i].y2;
}

int squaredDistanceToItem(int x, int y, int i) {
  return (x - items[i].x) * (x - items[i].x) + (y - items[i].y) * (y - items[i].y);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  char type;
  int n_items = 0, n_regions = 0;
  while (scanf("%c\n", &type) && type != '#') {
    if (type == 'I') {
      scanf("%d %d\n", &items[n_items].x, &items[n_items].y);
      items[n_items].visible = true;
      ++n_items;
      for (int i = 0; i < n_regions; ++i) {
        if (isInsideRegion(items[n_items - 1].x, items[n_items - 1].y, i)) {
          items[n_items - 1].visible = false;
          break;
        }
      }
    } else if (type == 'R') {
      scanf("%d %d %d %d\n", &regions[n_regions].x1, &regions[n_regions].y1,
          &regions[n_regions].x2, &regions[n_regions].y2);
      ++n_regions;
      for (int i = 0; i < n_items; ++i) {
        if (isInsideRegion(items[i].x, items[i].y, n_regions - 1)) {
          items[i].visible = false;
        }
      }
    } else {
      int x, y;
      scanf("%d %d\n", &x, &y);
      bool in_region = false;
      for (int i = n_regions - 1; i >= 0; --i) {
        if (isInsideRegion(x, y, i)) {
          printf("%c\n", i + 'A');
          in_region = true;
          break;
        }
      }
      if (in_region) {
        continue;
      }
      int d = INF;
      for (int i = 0; i < n_items; ++i) {
        if (items[i].visible) {
          d = min(d, squaredDistanceToItem(x, y, i));
        }
      }
      for (int i = 0; i < n_items; ++i) {
        if (items[i].visible && squaredDistanceToItem(x, y, i) == d) {
          printf("%3d", i + 1);
        }
      }
      printf("\n");
    }
  }
}

