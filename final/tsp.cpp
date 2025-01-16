#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp(int pos, int mask, vector<vector<int>> &dp, vector<vector<int>> grid, int n)
{
  if (mask == (1 << n) - 1)
    return grid[pos][0];

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
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> grid[i][j];

    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    cout << tsp(0, 1, dp, grid, n) << endl;
  }
}