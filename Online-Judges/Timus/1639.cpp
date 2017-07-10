/*
 * It doens't matter in which order they split the chocolate, but we know that if we
 * split in rows, we have more columns to split, and vice-versa.
 * So at the end, we have (n - 1 + (m - 1) * n) total splits. If this number is odd,
 * first player wins, otherwise, second player wins.
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  cout << ((n - 1 + (m - 1) * n) & 1 ? "[:=[first]" : "[second]=:]") << endl;
}

