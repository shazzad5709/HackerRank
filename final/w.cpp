#include <bits/stdc++.h>

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
    int n;
    cin >> n;

    int v = 2 * n + 2;

    vector<pair<int, int>> coords(v);
    vector<int> wc(n);
    vector<vector<Edge>> graph(v);
    vector<int> dist(v, INT_MAX);
    vector<bool> visited(v, false);

    dist[0] = 0;

    int sx, sy, dx, dy, c;
    cin >> sx >> sy >> dx >> dy;

    coords[0] = {sx, sy};
    coords[1] = {dx, dy};

    for (int i = 0; i < n; i++)
    {
      cin >> sx >> sy >> dx >> dy >> c;
      coords[2 * i + 2] = {sx, sy};
      coords[2 * i + 3] = {dx, dy};
      wc[i] = c;
    }

    auto dis = [&](int a, int b)
    {
      return abs(coords[a].first - coords[b].first) + abs(coords[a].second - coords[b].second);
    };

    for (int i = 0; i < v; i++)
    {
      for (int j = i + 1; j < v; j++)
      {
        int d = dis(i, j);
        graph[i].push_back({j, d});
        graph[j].push_back({i, d});
      }
    }

    for (int i = 0; i < n; i++)
    {
      int s = 2 * i + 2;
      int d = 2 * i + 3;
      graph[s].push_back({d, wc[i]});
      graph[d].push_back({s, wc[i]});
    }

    for (int _ = 0; _ < v; _++)
    {
      int best = INT_MAX;
      int u = -1;

      for (int i = 0; i < v; i++)
      {
        if (!visited[i] && dist[i] < best)
        {
          best = dist[i];
          u = i;
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
          dist[v] = dist[u] + cost;
      }
    }

    cout << dist[1] << endl;
  }
}