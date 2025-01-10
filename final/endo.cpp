#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dir[][4] = {
    {0, 0, 0, 0},
    {-1, 1, -1, 1},
    {0, 0, -1, 1},
    {-1, 1, 0, 0},
    {0, 1, -1, 0},
    {0, 1, 0, 1},
    {-1, 0, 0, 1},
    {-1, 0, -1, 0},
};

void dfs(int h, int w, int r, int c, int l, int &ans, vector<vector<int>> &dfsvisited, vector<vector<int>> &visited, vector<vector<int>> grid)
{
  if (r < 0 || r >= h || c < 0 || c >= w || dfsvisited[r][c] == 1 || grid[r][c] == 0 || l <= 0)
    return;

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

  if (c + left >= 0 && dir[grid[r][c + left]][1] == 1)
    dfs(h, w, r, c + left, l - 1, ans, dfsvisited, visited, grid);

  if (c + right < w && dir[grid[r][c + right]][0] == -1)
    dfs(h, w, r, c + right, l - 1, ans, dfsvisited, visited, grid);

  if (r + up >= 0 && dir[grid[r + up][c]][3] == 1)
    dfs(h, w, r + up, c, l - 1, ans, dfsvisited, visited, grid);

  if (r + down < h && dir[grid[r + down][c]][2] == -1)
    dfs(h, w, r + down, c, l - 1, ans, dfsvisited, visited, grid);

  dfsvisited[r][c] = 0;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int h, w, r, c, l;
    cin >> h >> w >> r >> c >> l;

    vector<vector<int>> grid(h, vector<int>(w));
    vector<vector<int>> visited(h, vector<int>(w, 0));
    vector<vector<int>> dfsvisited(h, vector<int>(w, 0));

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> grid[i][j];

    int ans = 0;

    dfs(h, w, r, c, l, ans, dfsvisited, visited, grid);

    cout << ans << endl;
  }
}