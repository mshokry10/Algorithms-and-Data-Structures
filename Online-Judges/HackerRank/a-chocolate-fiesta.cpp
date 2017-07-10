/*
 * Solved using simple classical dynamic programming.
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 100005, MOD = 1000000007;

int n;
int a[N];
int memo[N][2];

int solve(int i, int rem) {
    if (i == n) {
        return rem == 0;
    }
    int &ret = memo[i][rem];
    if (ret != -1) {
        return ret;
    }
    return ret = (solve(i + 1, (rem + a[i]) % 2) + solve(i + 1, rem)) % MOD;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    memset(memo, -1, sizeof memo);
    printf("%d\n", solve(0, 0) - 1);
    return 0;
}

