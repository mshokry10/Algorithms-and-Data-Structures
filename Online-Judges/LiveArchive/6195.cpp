/*
 * I sort the nodes topologically, and then if I can swap 2 neighboring nodes in the
 * topological order, it means that we have more than one topological order, otherwise
 * it's only one. If I can't topo-sort them, then there's 0.
 * I do topological sort by counting the in-edges for all nodes, and start with the ones
 * with 0 in-edges, decrement the in-edges of their neighbors and repeat the process. This
 * way I visit the nodes in their topological order.
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1003;

int in[N];
vector<int> adj[N];
int nodes[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int n, m;
  while (scanf("%d %d", &n, &m) && n && m) {
    memset(in, 0, sizeof in);
    for (int i = 0; i < n; ++i) {
      adj[i].clear();
    }
    while (m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      adj[u].push_back(v);
      ++in[v];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (in[i] == 0) {
        q.push(i);
      }
    }
    int cur = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      nodes[cur++] = u;
      for (int v : adj[u]) {
        --in[v];
        if (in[v] == 0) {
          q.push(v);
        }
      }
    }
    bool zero = 0;
    for (int i = 0; i < n; ++i) {
      if (in[i]) {
        zero = 1;
        break;
      }
    }
    if (zero) {
      puts("0");
      continue;
    }
    bool more = 0;
    for (int i = 0; i + 1 < n; ++i) {
      bool exists = 0;
      for (int v : adj[nodes[i]]) {
        if (v == nodes[i + 1]) {
          exists = 1;
          break;
        }
      }
      if (!exists) {
        more = 1;
        break;
      }
    }
    puts(more ? "2" : "1");
  }
}

