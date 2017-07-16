/*
 * The answer is the number of components of the given graph.
 * However, n is too large, so we could either use a map for the adjacency list,
 * or map the numbers to smaller numbers, since m < 10^5, which is what I've done.
 * Then I counted the number of components and the number of nodes in them using 
 * simple dfs.
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

vector<int> adj[N];
map<int, int> val;
bool vis[N];

int dfs(int u) {
  vis[u] = 1;
  int ret = 1;
  for (int v : adj[u]) {
    if (!vis[v]) {
      ret += dfs(v);
    }
  }
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  int cur = 1;
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    if (val[u]) {
      u = val[u];
    } else {
      u = val[u] = cur++;
    }
    if (val[v]) {
      v = val[v];
    } else {
      v = val[v] = cur++;
    }
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int cnt = 0, comp = 0;
  for (int i = 1; i < cur; ++i) {
    if (!vis[i]) {
      cnt += dfs(i);
      ++comp;
    }
  }
  printf("%d\n", n - cnt + comp);
}

