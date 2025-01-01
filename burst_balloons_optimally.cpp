#include <bits/stdc++.h>
using namespace std;

int n;

int ms(int left, int right, vector<int> &b, vector<vector<int>> &dp)
{
  if (left == right)
    return 0;

  if (dp[left][right] != -1)
    return dp[left][right];

  int msr = INT_MIN;

  for (int i = left; i < right; i++)
  {
    int score;
    if (left == 1 && right == n + 1)
      score = b[left - 1] * b[i] * b[right] + ms(left, i, b, dp) + ms(i + 1, right, b, dp);
    else
      score = b[left - 1] * b[right] + ms(left, i, b, dp) + ms(i + 1, right, b, dp);

    msr = max(msr, score);
  }

  return dp[left][right] = msr;
}

int main()
{

  cin >> n;
  vector<int> b(n + 2, 1);

  for (int i = 1; i <= n; i++)
    cin >> b[i];

  vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

  cout << ms(1, n + 1, b, dp);
}