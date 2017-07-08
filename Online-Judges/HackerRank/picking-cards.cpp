/*
 * Let cur = the number of cards we can choose, initially, with c_i = 0.
 * Let cnt[x] = the number of cards with c_i = x
 * At the first iteration, we have cur cards to choose from, at the second iteration,
 * we have cur - 1 + cnt[1] cards to choose from, because we remove the card we already
 * picked up, and now that we have 1 card, we add the cards with c_i = 1 to cur.
 * And we repeat the calculations until we pick up all the n cards.
 * The answer is the multiplication of cur values in each iteration, according to the
 * fundamental principle of counting.
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 50004, MOD = 1000000007;

int cnt[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      ++cnt[a];
    }
    long long res = cnt[0], cur = cnt[0];
    for (int i = 1; i < n; ++i) {
      cur = (cur - 1 + cnt[i]) % MOD;
      res = (res * cur) % MOD;
    }
    printf("%d\n", res);
  }
}
