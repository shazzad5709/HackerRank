#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(const vector<vector<int>> &grid, int n, int m, int d)
{
  if (n == 0 || m == 0)
    return false;

  int sr = n - 1;
  int sc = 0;

  if (grid[sr][sc] == 0)
    return false;

  // bfs
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  queue<pair<int, int>> q;

  q.push({sr, sc});

  while (!q.empty())
  {
    auto cell = q.front();
    int r = cell.first;
    int c = cell.second;
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
      int nc = c;

      // up
      int nrup = r - k;
      if (nrup >= 0)
      {
        if (!vis[nrup][nc] && (grid[nrup][nc] == 1 || grid[nrup][nc] == 3))
        {
          vis[nrup][nc] = true;
          q.push({nrup, nc});
        }
      }

      // down
      int nrdn = r + k;
      if (nrdn < n)
      {
        if (!vis[nrdn][nc] && (grid[nrdn][nc] == 1 || grid[nrdn][nc] == 3))
        {
          vis[nrdn][nc] = true;
          q.push({nrdn, nc});
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

    if (bfs(grid, n, m, mid))
    {
      ans = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }

  cout << ans << endl;
}