#include <iostream>
using namespace std;

int dfsvisited[15] = {0};
int adj[15][15];
int n, m;
int sum[15] = {0};
int mini = 1e9;
int ans[15];
int cycleLen = 0;
int visited[15] = {0};

void dfs(int node, int parent)
{
  dfsvisited[node] = dfsvisited[parent] + 1;
  sum[node] += node + sum[parent];
  visited[node] = 1;

  for (int i = 1; i <= n; i++)
  {
    if (adj[node][i] == -1)
      continue;

    int neighbor = i;
    if (dfsvisited[neighbor])
    {
      int cycleSum = sum[node] - sum[neighbor] + neighbor;
      if (cycleSum < mini)
      {
        int z = 0;
        for (int k = 1; k <= n; k++)
        {
          if (dfsvisited[k] >= dfsvisited[neighbor] && dfsvisited[k] <= dfsvisited[node])
          {
            ans[z] = k;
            z++;
          }
        }
        cycleLen = z;
        mini = cycleSum;
      }
    }
    else if (!dfsvisited[neighbor])
      dfs(neighbor, node);
  }
  dfsvisited[node] = 0;
  sum[node] = 0;
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      adj[i][j] = -1;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
  }

  for (int i = 1; i <= n; i++)
    if (!visited[i])
      dfs(i, 0);

  for (int i = 0; i < cycleLen; i++)
    cout << ans[i] << " ";
  cout << endl;

  return 0;
}