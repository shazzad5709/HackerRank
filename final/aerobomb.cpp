#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(5, 0));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < 5; j++)
        cin >> grid[i][j];

    queue<vector<int>> q;
    int ans = 0, score, bomb, r, c;

    q.push({0, n, 2, -1});

    while (!q.empty() && ans != -1)
    {
      auto it = q.front();

      score = it[0];
      r = it[1];
      c = it[2];
      bomb = it[3];

      q.pop();

      ans = max(ans, score);

      for (int i = -1; i <= 1; i++)
      {
        int nr = r - 1;
        int nc = c + i;

        if (nr < 0 || nc < 0 || nc >= 5)
          continue;

        if (grid[nr][nc] <= 1)
        {
          if (bomb == -1 || bomb - nr <= 4)
            q.push({score + grid[nr][nc], nr, nc, bomb});
        }
        else
        {
          if (bomb == -1)
            q.push({score, nr, nc, nr});
          else if (bomb - nr <= 4)
            q.push({score, nr, nc, bomb});
          else if (ans == 0)
          {
            ans = -1;
            break;
          }
        }
      }
    }

    cout << "#" << t << " " << ans << endl;
  }
}
