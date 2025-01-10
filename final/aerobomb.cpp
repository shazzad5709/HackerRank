#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    int ans = 0;

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(5, 0));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < 5; j++)
        cin >> grid[i][j];

    queue<vector<int>> q;

    q.push({0, n, 2, -1}); // score, row, column, bomb_used

    while (!q.empty())
    {
      auto it = q.front();
      int s = it[0];
      int r = it[1];
      int c = it[2];
      int b = it[3];

      q.pop();

      ans = max(ans, s);

      for (int i = -1; i <= 1; i++)
      {
        int nr = r - 1;
        int nc = c + i;

        if (nr < 0 || nc < 0 || nc >= 5)
          continue;

        if (grid[nr][nc] <= 1)
        {
          if (b == -1 || b - nr <= 4)
            q.push({s + grid[nr][nc], nr, nc, b});
        }
        else
        {
          if (b == -1)
            q.push({s, nr, nc, nr});
          else if (b - nr <= 4)
            q.push({s, nr, nc, b});
        }
      }
    }

    cout << "#" << t << " " << ans << endl;
  }
}