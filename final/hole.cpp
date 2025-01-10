#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge
{
  int to;
  int cost;
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--)
  {
    int n, sx, sy, dx, dy, c;
    cin >> n;

    int v = n * 2 + 2;

    vector<pair<int, int>> coords(v);
    vector<vector<Edge>> graph(v);
    vector<int> dist(v, INT_MAX);
    vector<bool> visited(v, false);
    vector<int> wc(n);

    dist[0] = 0;

    auto distance = [&](int a, int b)
    {
      return abs(coords[a].first - coords[b].first) + abs(coords[a].second - coords[b].second);
    };

    cin >> sx >> sy >> dx >> dy;

    coords[0] = {sx, sy};
    coords[1] = {dx, dy};

    for (int i = 0; i < n; i++)
    {
      cin >> sx >> sy >> dx >> dy >> c;
      coords[i * 2 + 2] = {sx, sy};
      coords[i * 2 + 3] = {dx, dy};

      wc[i] = c;
    }

    for (int i = 0; i < v; i++)
    {
      for (int j = i + 1; j < v; j++)
      {
        int cost = distance(i, j);
        graph[i].push_back({j, cost});
        graph[j].push_back({i, cost});
      }
    }

    for (int i = 0; i < n; i++)
    {
      int s = i * 2 + 2;
      int d = i * 2 + 3;

      graph[s].push_back({d, wc[i]});
      graph[d].push_back({s, wc[i]});
    }

    for (int _ = 0; _ < v; _++)
    {
      int u = -1;
      int bestDist = INT_MAX;

      for (int i = 0; i < v; i++)
      {
        if (!visited[i] && dist[i] < bestDist)
        {
          u = i;
          bestDist = dist[i];
        }
      }

      if (u == -1)
        break;

      visited[u] = true;

      if (u == 1)
        break;

      for (auto &edge : graph[u])
      {
        int v = edge.to;
        int cost = edge.cost;

        if (!visited[v] && dist[u] + cost < dist[v])
        {
          dist[v] = dist[u] + cost;
        }
      }
    }

    cout << dist[1] << endl;
  }
}