#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <cstring>

using namespace std;

// static int dp[11][11][11][11];
int g0, g1, g2;

int n;

int sol(int idx, int p0, int p1, int p2)
{
  if (p0 + p1 + p2 == 0)
    return 0;

  if (idx > n)
    return INT_MAX;

  // if (dp[idx][p0][p1][p2] != -1)
  //   return dp[idx][p0][p1][p2];

  int best = sol(idx + 1, p0, p1, p2);

  if (p0 > 0)
  {
    int cost = abs(g0 - idx) + 1;
    int rec = sol(idx + 1, p0 - 1, p1, p2);

    if (rec != INT_MAX)
      best = min(best, cost + rec);
  }

  if (p1 > 0)
  {
    int cost = abs(g1 - idx) + 1;
    int rec = sol(idx + 1, p0, p1 - 1, p2);

    if (rec != INT_MAX)
      best = min(best, cost + rec);
  }

  if (p2 > 0)
  {
    int cost = abs(g2 - idx) + 1;
    int rec = sol(idx + 1, p0, p1, p2 - 1);

    if (rec != INT_MAX)
      best = min(best, cost + rec);
  }

  return best;
}

int main()
{
  cin >> n;

  int p0, p1, p2;

  cin >> g0 >> g1 >> g2;
  cin >> p0 >> p1 >> p2;

  memset(dp, -1, sizeof(dp));

  cout << sol(1, p0, p1, p2) << endl;
}