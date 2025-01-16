#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void printCycle(vector<int> &parent, int start, int end)
{
  vector<int> cycle;
  int current = start;
  while (current != end)
  {
    cycle.push_back(current);
    current = parent[current];
  }
  cycle.push_back(end);
  for (int node : cycle)
  {
    cout << node << " ";
  }
  cout << endl;
}

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inStack, vector<int> &parent)
{
  visited[node] = true;
  inStack[node] = true;

  for (int neighbor : adj[node])
  {
    if (!visited[neighbor])
    {
      parent[neighbor] = node;
      if (dfs(neighbor, adj, visited, inStack, parent))
      {
        return true;
      }
    }
    else if (inStack[neighbor])
    {
      printCycle(parent, node, neighbor);
      return true;
    }
  }

  inStack[node] = false;
  return false;
}

int main()
{
  int N, M;
  cin >> N >> M;

  vector<vector<int>> adj(N + 1); // adjacency list
  for (int i = 0; i < M; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  vector<bool> visited(N + 1, false);
  vector<bool> inStack(N + 1, false);
  vector<int> parent(N + 1, -1);

  for (int i = 1; i <= N; i++)
  {
    if (!visited[i])
    {
      if (dfs(i, adj, visited, inStack, parent))
      {
        return 0; // A cycle was found and printed
      }
    }
  }

  cout << 0 << endl; // No cycle found
  return 0;
}
