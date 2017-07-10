#include <bits/stdc++.h>

using namespace std;

const int N = 1000006;

long long res[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  long long p = 1, q = 0, even = 2;
  for (int i = 3; i < N; ++i) {
    res[i] = res[i - 1] + (i & 1 ? q : p * p);
    p += i & 1 ? 0 : 1;
    q += i & 1 ? even : 0;
    even += i & 1 ? 2 : 0;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", res[n]);
  }
}

