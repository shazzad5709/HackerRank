#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int dist(pair<int, int> n1, pair<int, int> n2)
{
  return abs(n1.first - n2.first) + abs(n1.second - n2.second);
}

int tsp(int pos, int mask, vector<vector<int>> &dp, vector<vector<int>> grid, int n)
{
  if (mask == (1 << n) - 1)
    return grid[pos][n - 1];

  if (dp[pos][mask] != -1)
    return dp[pos][mask];

  int ans = INT_MAX;

  for (int next = 1; next < n; next++)
  {
    if ((mask & (1 << next)) == 0)
    {
      int cost = grid[pos][next] + tsp(next, mask | (1 << next), dp, grid, n);
      ans = min(ans, cost);
    }
  }

  return dp[pos][mask] = ans;
}

int main()
{
  int T = 10;
  while (T--)
  {
    int n;
    cin >> n;
    n += 2;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<pair<int, int>> coords(n);
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    int x, y;
    cin >> x >> y;
    coords[0] = {x, y};
    cin >> x >> y;
    coords[n - 1] = {x, y};

    for (int i = 1; i < n - 1; i++)
    {
      cin >> x >> y;
      coords[i] = {x, y};
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        grid[i][j] = dist(coords[i], coords[j]);
        grid[j][i] = dist(coords[i], coords[j]);
      }
    }

    cout << "# " << (10 - T) << " " << tsp(0, 1, dp, grid, n) << endl;
  }
}