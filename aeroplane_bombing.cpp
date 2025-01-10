#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
  int test_case;
  cin >> test_case;

  for (int i = 1; i <= test_case; i++)
  {
    int no_of_rows;
    cin >> no_of_rows;

    vector<vector<int>> a(no_of_rows, vector<int>(5, -1));

    for (int i = 0; i < no_of_rows; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        cin >> a[i][j];
      }
    }

    int ans = 0;
    int score, row, col, bomb_used;

    queue<vector<int>> q; // score,row,col,bomb_used
    q.push({0, no_of_rows, 2, -1});

    while (!q.empty())
    {
      auto it = q.front();
      q.pop();
      score = it[0];
      row = it[1];
      col = it[2];
      bomb_used = it[3];
      ans = max(ans, score);

      for (int i = -1; i <= 1; i++)
      {
        int new_row = row - 1;
        int new_col = col + i;

        if (new_row < 0 || new_col < 0 || new_col >= 5)
          continue;

        if (a[new_row][new_col] <= 1)
        {
          if (bomb_used == -1 || bomb_used - new_row <= 4)
            q.push({score + a[new_row][new_col], new_row, new_col, bomb_used});
        }

        else
        {
          if (bomb_used == -1)
            q.push({score, new_row, new_col, new_row});

          else if (bomb_used - new_row <= 4)
            q.push({score, new_row, new_col, bomb_used});
        }
      }
    }

    cout << "#" << i << " " << ans << endl;
  }
}
