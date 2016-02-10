/**
 * Segment Tree with Lazy Propagation
 * Change the type defined (int, long, etc.)
 * Change the combine() and updateNode() functions
 * Change the value of N and INVALID
 */
#include <bits/stdc++.h>

using namespace std;

typedef int type;

const int N = 100005;
const type INVALID = 0;

// Data
int a[N], n;

type st[4 * N];
type lazy[4 * N];

type combine(type x, type y) {
  return x + y;
}

type updateNode(type node, type val, int l, int r) {
  return node + val * (r - l + 1);
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

void update(int l, int r, int x, int y, int val, int i = 1) {
  int li = i << 1, ri = li + 1;
  if (lazy[i] != 0) {
    st[i] = updateNode(st[i], lazy[i], l, r);
    if (l != r) {
      lazy[li] += lazy[i];
      lazy[ri] += lazy[i];
    }
    lazy[i] = 0;
  }
  if (y < l || r < x)
    return;
  if (x <= l && r <= y) {
    st[i] = updateNode(st[i], val, l, r);
    if (l != r) {
      lazy[li] += val;
      lazy[ri] += val;
    }
    return;
  }
  int mid = (l + r) >> 1;
  update(l, mid, x, y, val, li);
  update(mid + 1, r, x, y, val, ri);
  st[i] = combine(st[li], st[ri]);
}

type query(int l, int r, int x, int y, int i = 1) {
  int li = i << 1, ri = li + 1;
  if (lazy[i] != 0) {
    st[i] = updateNode(st[i], lazy[i], l, r);
    if (l != r) {
      lazy[li] += lazy[i];
      lazy[ri] += lazy[i];
    }
    lazy[i] = 0;
  }
  if (r < x || l > y)
    return INVALID;
  if (x <= l && r <= y)
    return st[i];
  int mid = (l + r) >> 1;
  type ql = query(l, mid, x, y, li);
  type qr = query(mid + 1, r, x, y, ri);
  return combine(ql, qr);
}

int main() {
  n = 10;
  for (int i = 0; i < n; ++i)
    a[i] = i + 1;
  build(0, n - 1);
  cout << query(0, n - 1, 0, n - 1) << endl;
  update(0, n - 1, 0, n - 1, 10);
  cout << query(0, n - 1, 0, n - 1) << endl;
  cout << query(0, n - 1, 1, n - 2) << endl;
}
