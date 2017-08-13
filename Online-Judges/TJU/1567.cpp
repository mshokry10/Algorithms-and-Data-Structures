/*
 * First of all, we know that if the slopes of the 2 lines are equal, then the lines are either parallel or
 * the same. To chech that, we can check whether a point of the first line lies on the second line, then we
 * can easily determine whether the answer is "none" or "line".
 * Otherwise, we need to find the point of intersection.
 * Using the slope equations of the 2 lines and some simple algebra we will get 2 equations with 2 unknowns that
 * we can solve simply for the intersection point (x, y).
 */
 
#include <bits/stdc++.h>
 
using namespace std;
 
const double EPS = 1E-9;
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    puts("INTERSECTING LINES OUTPUT");
    while (t--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        if ((y2 - y1) * (x4 - x3) == (y4 - y3) * (x2 - x1)) {
            puts((y2 - y1) * (x4 - x1) == (y4 - y1) * (x2 - x1) ? "LINE" : "NONE");
        } else {
            double x = ((x2 - x1) * (x4 - x3) * y3 - (x2 - x1) * (x4 - x3) * y1 -
                        (x2 - x1) * (y4 - y3) * x3 + (y2 - y1) * (x4 - x3) * x1) /
                    ((y2 - y1) * (x4 - x3) - (x2 - x1) * (y4 - y3) + EPS);
            double y;
            if (x1 != x2) {
                y = ((y2 - y1) * x - (y2 - y1) * x1 + (x2 - x1) * y1) / (x2 - x1);
            } else {
                y = ((y4 - y3) * x - (y4 - y3) * x3 + (x4 - x3) * y3) / (x4 - x3);
            }
            printf("POINT %.2lf %.2lf\n", x, y);
        }
    }
    puts("END OF OUTPUT");
    return 0;
}
