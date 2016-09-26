#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int parent[N], size[N], rnk[N];
int n;

void init() {
  memset(rnk, 0, sizeof rnk);
  for (int i = 0; i < n; ++i) {
    parent[i] = i;
    size[i] = 1;
  }
}

int root(int node) {
  while (node != parent[node]) {
    parent[node] = parent[parent[node]];
    node = parent[node];
  }
  return node;
}

bool join(int u, int v) {
  u = root(u);
  v = root(v);

  if (u == v)
    return false;

  if (rnk[u] < rnk[v])
    swap(u, v);

  rnk[u] += rnk[u] == rnk[v];
  size[u] += size[v];

  parent[v] = u;
  return true;
}

int find(int u, int v) {
  return root(u) == root(v);
}

int main() {
  int m;
  scanf("%d %d", &n, &m);
  init(); // initialize
  while (m--) {
    int q, u, v;
    scanf("%d %d %d", &q, &u, &v);
    --u, --v; // 1-based
    if (q == 1) // join
      join(u, v);
    else
      printf("%d\n", (int)find(u, v));
  }
}

