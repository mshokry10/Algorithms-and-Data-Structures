// Sieve of Eratosthenes

#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

vector<bool> isPrime(N, true);
vector<int> primes;

void sieve() {
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j < N; j += i)
        isPrime[j] = false;
    }
  }
  for (int i = 2; i <= N; ++i) {
    if (isPrime[i])
      primes.push_back(i);
  }
}

// Test
int main() {
  sieve();
  for (int i = 0; i < 20; ++i)
    cout << primes[i] << endl;
}
