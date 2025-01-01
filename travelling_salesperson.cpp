#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int tsp(int pos, int mask, vector<vector<int>> &dist, vector<vector<int>> &dp, int N)
{
  if (mask == (1 << N) - 1)
  {
    return dist[pos][0];
  }

  if (dp[pos][mask] != -1)
  {
    return dp[pos][mask];
  }

  int ans = INF;

  for (int next = 0; next < N; next++)
  {
    if ((mask & (1 << next)) == 0)
    {
      int newAns = dist[pos][next] + tsp(next, mask | (1 << next), dist, dp, N);
      ans = min(ans, newAns);
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
    int N;
    cin >> N;
    vector<vector<int>> dist(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cin >> dist[i][j];
      }
    }

    vector<vector<int>> dp(N, vector<int>(1 << N, -1));
    cout << tsp(0, 1, dist, dp, N) << endl;
  }
}
