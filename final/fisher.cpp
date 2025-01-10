#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

int n;
int gate[3];
static int dp[11][11][11][11];

int sol(int idx, int p0, int p1, int p2)
{
  if (p0 + p1 + p2 == 0)
    return 0;

  if (idx > n)
    return INT_MAX;

  int best = sol(idx + 1, p0, p1, p2);

  if (p0 > 0)
  {
    int cost = abs(gate[0] - idx) + 1;
    int rec = sol(idx + 1, p0 - 1, p1, p2);

    if (rec != INT_MAX)
      best = min(best, cost + rec);
  }

  if (p1 > 0)
  {
    int cost = abs(gate[1] - idx) + 1;
    int rec = sol(idx + 1, p0, p1 - 1, p2);

    if (rec != INT_MAX)
      best = min(best, cost + rec);
  }

  if (p2 > 0)
  {
    int cost = abs(gate[2] - idx) + 1;
    int rec = sol(idx + 1, p0, p1, p2 - 1);

    if (rec != INT_MAX)
      best = min(best, cost + rec);
  }

  return best;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int p0, p1, p2;
  cin >> n;
  for (int i = 0; i < 3; i++)
    cin >> gate[i];

  cin >> p0 >> p1 >> p2;

  memset(dp, -1, sizeof(dp));

  cout << sol(1, p0, p1, p2) << endl;
}