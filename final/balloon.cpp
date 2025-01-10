#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;

int sol(int l, int r, vector<int> &b, vector<vector<int>> &dp)
{
  if (l == r)
    return 0;

  if (dp[l][r] != -1)
    return dp[l][r];

  int msr = INT_MIN;

  for (int i = l; i < r; i++)
  {
    int score;
    if (l == 1 && r == n + 1)
      score = b[i] + sol(l, i, b, dp) + sol(i + 1, r, b, dp);
    else
      score = b[l - 1] * b[r] + sol(l, i, b, dp) + sol(i + 1, r, b, dp);

    msr = max(msr, score);
  }

  return dp[l][r] = msr;
}

int main()
{
  cin >> n;
  vector<int> b(n + 2, 1);

  for (int i = 1; i <= n; i++)
  {
    cin >> b[i];
  }

  vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

  cout << sol(1, n + 1, b, dp) << endl;
}