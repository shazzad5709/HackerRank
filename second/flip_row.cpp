#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  int arr[15][15];
  unordered_map<string, int> pc;
  for (int i = 0; i < n; i++)
  {
    string s;
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
      s += arr[i][j] + '0';
    }
    pc[s]++;
  }

  int ans = INT_MIN;

  for (auto p : pc)
  {
    int c = 0;
    for (auto cell : p.first)
      c += (cell == '0');

    if (c <= k && ((k - c) % 2) == 0)
      ans = max(ans, p.second);
  }

  cout << ans;
}