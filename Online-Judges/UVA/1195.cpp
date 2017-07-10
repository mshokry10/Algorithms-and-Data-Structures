/*
 * I just generated all prime numbers up to 10^5, and brute-forced the solution, after
 * calculating and making sure that this is going to fit in time.
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

bool is_prime[N];
long long p[N];
int n = 0;

void sieve() {
  for (int i = 2; i < N; ++i) {
    is_prime[i] = 1;
  }
  for (int i = 2; i * i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j < N; j += i) {
        is_prime[j] = 0;
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    if (is_prime[i]) {
      p[n++] = i;
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  sieve();
  int m, a, b;
  while (scanf("%d %d %d", &m, &a, &b) && m && a && b) {
    int mx = 0, p1 = 0, p2 = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n && a * p[j] <= b * p[i] && p[i] * p[j] <= m; ++j) {
        if (p[i] * p[j] > mx) {
          p1 = p[i];
          p2 = p[j];
          mx = p[i] * p[j];
        }
      }
    }
    printf("%d %d\n", p1, p2);
  }
}

