#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<vector<int>> grid(15, vector<int>(15, 0));

static const int MAXR = 20;
int memo[25][10][25][2];

bool usedMemo[25][10][25][2];

int findCoins(int r, int c, int br, int b)
{
  if (r < 0)
    return 0;

  int R = min(max(r, 0), 24);
  int C = min(max(c, 0), 9);
  int BR = min(max(br, 0), 24);
  int B = (b == 0 ? 0 : 1);

  if (usedMemo[R][C][BR][B])
    return memo[R][C][BR][B];

  if (grid[r][c] == 2 && b == 0 && br > 5)
  {
    usedMemo[R][C][BR][B] = true;
    memo[R][C][BR][B] = 0;
    return 0;
  }

  int coin = (grid[r][c] == 1) ? 1 : 0;

  int ans = 0;

  for (int i = -1; i <= 1; i++)
  {
    int nc = c + i;
    if (nc < 0 || nc >= 5)
      continue;

    if (b == 0 || grid[r][c] == 2)
      ans = max(ans, findCoins(r - 1, nc, br + 1, 0));
    else
      ans = max(ans, max(findCoins(r - 1, nc, 1, 1),
                         findCoins(r - 1, nc, br + 1, 0)));
  }

  int best = ans + coin;

  memo[R][C][BR][B] = best;
  usedMemo[R][C][BR][B] = true;
  return best;
}

void solve()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++)
      cin >> grid[i][j];

  for (int i = n; i < 15; i++)
    for (int j = 0; j < 5; j++)
      grid[i][j] = 0;

  memset(usedMemo, false, sizeof(usedMemo));

  int c = 2;
  int r = n - 1;
  int ans = 0;
  for (int i = -1; i <= 1; i++)
  {
    int startCol = c + i;
    if (startCol < 0 || startCol >= 5)
      continue;
    ans = max(ans, findCoins(r, startCol, 1, 1));
  }

  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; i++)
  {
    cout << "#" << i << " ";
    solve();
  }
  return 0;
}
