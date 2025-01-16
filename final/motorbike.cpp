#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

void printCycle(vector<int> &parents, int start, int end)
{
  vector<int> cycle;
  int current = start;
  while (current != end)
  {
    cycle.push_back(current);
    current = parents[current];
  }
  cycle.push_back(end);

  sort(cycle.begin(), cycle.end());

  for (int node : cycle)
  {
    cout << node << " ";
  }
  cout << endl;
}

bool dfs(int node, const vector<vector<int>> &adj, vector<int> &parents, vector<bool> &vis, vector<bool> &stk)
{
  vis[node] = true;
  stk[node] = true;

  for (int nb : adj[node])
  {
    if (!vis[nb])
    {
      parents[nb] = node;
      if (dfs(nb, adj, parents, vis, stk))
        return true;
    }
    else if (stk[nb])
    {
      printCycle(parents, node, nb);
      return true;
    }
  }

  stk[node] = false;
  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<bool> vis(n + 1, false);
  vector<bool> stk(n + 1, false);
  vector<int> parents(n + 1);

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  for (int i = 1; i <= n; i++)
    if (dfs(i, adj, parents, vis, stk))
      return 0;

  cout << "0" << endl;
}