#include <iostream>
#include <vector>

using namespace std;

bool isBipertite(int i, const vector<vector<int>> &adj, vector<int> &color, int n)
{
  bool flag = true;

  for (int j = 0; j < n; j++)
  {
    if (adj[i][j] == 1)
    {
      if (color[j] == -1)
      {
        color[j] = 1 - color[i];
        flag = flag & isBipertite(j, adj, color, n);
      }
      else if (color[j] == color[i])
        return false;
    }
  }

  return flag;
}

int main()
{
  int n;
  cin >> n;

  vector<vector<int>> adj(n, vector<int>(n));
  vector<int> color(n, -1);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> adj[i][j];

  for (int i = 0; i < n; i++)
  {
    if (color[i] == -1)
    {
      color[i] = 0;
      if (!isBipertite(i, adj, color, n))
      {
        cout << "-1" << endl;
        return 0;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (color[i] == 0)
      cout << i << " ";
  }
}