#include <iostream>
#include <vector>

using namespace std;

bool isBipartite(const vector<vector<int>> &adj, int i, vector<int> &color, int n)
{
  bool flag = true;
  for (int j = 0; j < n; j++)
  {
    if (adj[i][j] == 1)
    {
      if (color[j] == -1)
      {
        color[j] = 1 - color[i];
        flag = flag & isBipartite(adj, j, color, n);
      }
      else if (color[i] == color[j])
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

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> adj[i][j];

  vector<int> color(n, -1);

  for (int i = 0; i < n; i++)
  {
    if (color[i] == -1)
    {
      color[i] = 0;
      if (!isBipartite(adj, i, color, n))
      {
        cout << "-1" << endl;
        return 0;
      }
    }
  }

  for (int i = 0; i < n; i++)
    if (color[i] == 0)
      cout << i << " ";

  return 0;
}