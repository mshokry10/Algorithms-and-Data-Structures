/**
 * Segment Tree (Range query and single element update)
 * Change the defined type (int, long long, etc.)
 * Change the combine() function
 * Change the value of N and INVALID
 */
#include <bits/stdc++.h>

using namespace std;

typedef int type;

const int N = 100005;
const type INVALID = 0;

// Data ..
int a[N], n;

type st[4 * N];

type combine(type x, type y) {
  return x + y;
}

void build(int l, int r, int i = 1) {
  if (l == r) {
    st[i] = a[l];
    return;
  }
  int mid = (l + r) >> 1, li = i << 1, ri = li + 1;
  build(l, mid, li);
  build(mid + 1, r, ri);
  st[i] = combine(st[li], st[ri]);
}

void update(int l, int r, int x, int val, int i = 1) {
  if (x < l || r < x)
    return;
  if (l == r) {
    st[i] += val;
    return;
  }
  int mid = (l + r) >> 1, li = i << 1, ri = li + 1;
  update(l, mid, x, val, li);
  update(mid + 1, r, x, val, ri);
  st[i] = combine(st[li], st[ri]);
}

type query(int l, int r, int x, int y, int i = 1) {
  if (r < x || l > y)
    return INVALID;
  if (x <= l && r <= y)
    return st[i];
  int mid = (l + r) >> 1, li = i << 1, ri = li + 1;
  type ql = query(l, mid, x, y, li);
  type qr = query(mid + 1, r, x, y, ri);
  return combine(ql, qr);
}

// Testing
int main() {
  n = 10;
  for (int i = 0; i < n; ++i)
    a[i] = i + 1;
  build(0, n - 1);
  cout << query(0, n - 1, 0, n - 1) << endl;
  update(0, n - 1, 3, 10);
  cout << query(0, n - 1, 0, n - 1) << endl;
  cout << query(0, n - 1, 1, n - 2) << endl;
}
