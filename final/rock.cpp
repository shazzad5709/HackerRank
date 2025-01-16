#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canReachGoalBFS(const vector<vector<int>> &grid, int n, int m, int d)
{
  int startR = n - 1;
  int startC = 0;

  vector<vector<bool>> vis(n, vector<bool>(m, false));
  vis[startR][startC] = true;

  queue<pair<int, int>> q;
  q.push({startR, startC});

  while (!q.empty())
  {
    auto cell = q.front();
    int r = cell.first, c = cell.second;

    q.pop();

    if (grid[r][c] == 3)
      return true;

    // left
    if (c - 1 >= 0)
    {
      int nr = r;
      int nc = c - 1;

      if (!vis[nr][nc] && (grid[nr][nc] == 1 || grid[nr][nc] == 3))
      {
        vis[nr][nc] = true;
        q.push({nr, nc});
      }
    }

    // right
    if (c + 1 < m)
    {
      int nr = r;
      int nc = c + 1;

      if (!vis[nr][nc] && (grid[nr][nc] == 1 || grid[nr][nc] == 3))
      {
        vis[nr][nc] = true;
        q.push({nr, nc});
      }
    }

    // up and down
    for (int k = 1; k <= d; k++)
    {
      // up
      int nrUp = r - k;

      if (nrUp >= 0)
      {
        if (!vis[nrUp][c] && (grid[nrUp][c] == 1 || grid[nrUp][c] == 3))
        {
          vis[nrUp][c] = true;
          q.push({nrUp, c});
        }
      }

      // down
      int nrDown = r + k;
      if (nrDown < n)
      {
        if (!vis[nrDown][c] && (grid[nrDown][c] == 1 || grid[nrDown][c] == 3))
        {
          vis[nrDown][c] = true;
          q.push({nrDown, c});
        }
      }
    }
  }

  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];

  int high = n - 1;
  int low = 0;
  int ans = -1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (canReachGoalBFS(grid, n, m, mid))
    {
      ans = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }

  cout << ans << endl;
}