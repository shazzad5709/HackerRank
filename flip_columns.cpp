#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  unordered_map<string, int> pc;
  vector<vector<int>> mat(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
  {
    string s;
    for (int j = 0; j < m; j++)
    {
      cin >> mat[i][j];
      s += to_string(mat[i][j]);
    }
    pc[s]++;
  }

  int ans = 0;

  for (const auto it : pc)
  {
    int c = 0;
    for (int cell : it.first)
    {

      c += (cell == '0');
    }

    if ((c <= k) && (k - c) % 2 == 0)
    {
      ans = max(ans, it.second);
    }
  }
  cout << ans;
}