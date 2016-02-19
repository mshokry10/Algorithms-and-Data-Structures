/**
 * Trie (Prefix Tree)
 * Change the value of N and CHARSET
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int CHARSET = 26;
const int ROOT = 0;

int nxt[N][CHARSET];
bool en[N];
int sz = 1;

void insert(char s[]) {
  int node = ROOT;
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    if (!nxt[node][s[i] - 'a'])
      nxt[node][s[i] - 'a'] = sz++;
    node = nxt[node][s[i] - 'a'];
  }
  en[node] = true;
}

bool find(char s[]) {
  int node = ROOT;
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    if (!nxt[node][s[i] - 'a'])
      return false;
    node = nxt[node][s[i] - 'a'];
  }
  return en[node];
}

// Test
int main() {
  insert("hello");
  insert("hell");
  insert("he");
  cout << find("hell") << endl;
  cout << find("hel") << endl;
  cout << find("he") << endl;
  cout << find("hello") << endl;
  cout << find("helloo") << endl;
}
