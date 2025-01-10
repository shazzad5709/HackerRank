#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int dir[][4] = {
    {0, 0, 0, 0},
    {-1, 1, -1, 1},
    {0, 0, -1, 1},
    {-1, 1, 0, 0},
    {0, 1, -1, 0},
    {0, 1, 0, 1},
    {-1, 0, 0, 1},
    {-1, 0, -1, 0},
};

void dfs(const vector<vector<int>> &grid, vector<vector<int>> &visited, vector<vector<int>> &dfsvisited, int w, int h, int r, int c, int &ans, int l)
{
  if (r < 0 || r >= h || c < 0 || c >= w || grid[r][c] == 0 || dfsvisited[r][c] == 1 || l <= 0)
  {
    return;
  }

  if (!visited[r][c])
  {
    ans++;
  }
  visited[r][c] = 1;
  dfsvisited[r][c] = 1;

  int left = dir[grid[r][c]][0];
  int right = dir[grid[r][c]][1];
  int up = dir[grid[r][c]][2];
  int down = dir[grid[r][c]][3];

  // Move left
  if (c + left >= 0 && c + left < w && dir[grid[r][c]][0] == -1 && dir[grid[r][c + left]][1] == 1)
  {
    dfs(grid, visited, dfsvisited, w, h, r, c + left, ans, l - 1);
  }

  // Move right
  if (c + right >= 0 && c + right < w && dir[grid[r][c]][1] == 1 && dir[grid[r][c + right]][0] == -1)
  {
    dfs(grid, visited, dfsvisited, w, h, r, c + right, ans, l - 1);
  }

  // Move up
  if (r + up >= 0 && r + up < h && dir[grid[r][c]][2] == -1 && dir[grid[r + up][c]][3] == 1)
  {
    dfs(grid, visited, dfsvisited, w, h, r + up, c, ans, l - 1);
  }

  // Move down
  if (r + down >= 0 && r + down < h && dir[grid[r][c]][3] == 1 && dir[grid[r + down][c]][2] == -1)
  {
    dfs(grid, visited, dfsvisited, w, h, r + down, c, ans, l - 1);
  }

  dfsvisited[r][c] = 0;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int h, w, r, c, l;
    cin >> h >> w >> r >> c >> l;

    vector<vector<int>> grid(h, vector<int>(w));
    vector<vector<int>> visited(h, vector<int>(w, 0));
    vector<vector<int>> dfsvisited(h, vector<int>(w, 0));

    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        cin >> grid[i][j];
      }
    }

    int ans = 0;
    dfs(grid, visited, dfsvisited, w, h, r, c, ans, l);
    cout << ans << endl;
  }
  return 0;
}