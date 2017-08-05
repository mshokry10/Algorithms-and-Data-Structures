/*
 * Recursive brute force with memoization.
 * The state consists of the current position of both the bishop and the pawn, and which
 * player's turn it is. At each state, I try all possible moves for the current player.
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 8;
const int signX[] = {1, 1, -1, -1};
const int signY[] = {1, -1, 1, -1};

int memo[N][N][N][N][2];
bool vis[N][N][N][N][2];

bool valid(int i, int j) {
  return i >= 0 && j >= 0 && i < N && j < N;
}

bool pawnCanCapture(int i, int j, int x, int y) {
  return x == i + 1 && (y == j + 1 || y == j - 1);
}

bool bishopCanCapture(int x, int y, int i, int j) {
  for (int idx = 0; idx < 4; ++idx) {
    for (int k = 1; k < N; ++k) {
      if (!valid(x + signX[idx] * k, y + signY[idx] * k)) {
        break;
      }
      if (x + signX[idx] * k == i && y + signY[idx] * k == j) {
        return true;
      }
    }
  }
  return false;
}

bool pawnCanMove(int i, int j, int x, int y) {
  return i + 1 != x || j != y;
}

int blackWins(int i, int j, int x, int y, int turn) {
  if (i == N - 1) {
    return bishopCanCapture(x, y, i, j) ? -1 : 1;
  }

  int &ret = memo[i][j][x][y][turn];
  if (vis[i][j][x][y][turn]) {
    return ret;
  }
  vis[i][j][x][y][turn] = true;

  if (turn == 0) {
    if (bishopCanCapture(x, y, i, j)) {
      return ret = -1;
    }
    bool canDraw = false;
    for (int idx = 0; idx < 4; ++idx) {
      for (int k = 1; k < N; ++k) {
        if (!valid(x + signX[idx] * k, y + signY[idx] * k)) {
          break;
        }
        int state = blackWins(i, j, x + signX[idx] * k, y + signY[idx] * k, 1);
        if (state == -1) {
          return ret = -1;
        }
        if (state == 0) {
          canDraw = true;
        }
      }
    }
    return ret = canDraw ? 0 : 1;
  } else {
    if (pawnCanCapture(i, j, x, y)) {
      return ret = 1;
    }
    if (!pawnCanMove(i, j, x, y)) {
      return ret = 0;
    }
    return ret = blackWins(i + 1, j, x, y, 0);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif
  int i, j, x, y;
  char c1, c2;
  scanf("%c%d %c%d", &c1, &x, &c2, &i);
  x = N - x;
  y = N - (c1 - 'a') - 1;
  i = N - i;
  j = N - (c2 - 'a') - 1;
  if (blackWins(i, j, x, y, 0) == 1) {
    puts("BLACK");
  } else if (blackWins(i, j, x, y, 0) == -1) {
    puts("WHITE");
  } else {
    puts("DRAW");
  }
}

