#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

void printCycle(const vector<int> &parents, int start, int end)
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
    cout << node << " ";

  cout << endl;
}

bool dfs(int node, const vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &dfsvisited, vector<int> &parents)
{
  visited[node] = true;
  dfsvisited[node] = true;

  for (int neighbor : adj[node])
  {
    if (!visited[neighbor])
    {
      parents[neighbor] = node;
      if (dfs(neighbor, adj, visited, dfsvisited, parents))
        return true;
    }
    else if (dfsvisited[neighbor])
    {
      printCycle(parents, node, neighbor);
      return true;
    }
  }

  dfsvisited[node] = false;
  return false;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--)
  {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vector<bool> dfsvisited(n + 1, false);
    vector<int> parents(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }

    int flag = false;

    for (int i = 1; i <= n; i++)
    {
      if (!visited[i])
      {
        if (dfs(i, adj, visited, dfsvisited, parents))
        {
          flag = true;
          break;
        }
      }
    }

    if (!flag)
      cout << "0" << endl;
  }
}