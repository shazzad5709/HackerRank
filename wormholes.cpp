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

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int Sx, Sy, Dx, Dy;
        cin >> Sx >> Sy >> Dx >> Dy;

        int V = 2 + 2 * N;
        vector<pair<int, int>> coords(V);

        coords[0] = {Sx, Sy};

        coords[1] = {Dx, Dy};

        vector<int> wormholeCost(N);
        for (int i = 0; i < N; i++)
        {
            int x1, y1, x2, y2, cost;
            cin >> x1 >> y1 >> x2 >> y2 >> cost;
            coords[2 + 2 * i] = {x1, y1};
            coords[2 + 2 * i + 1] = {x2, y2};
            wormholeCost[i] = cost;
        }

        vector<vector<Edge>> graph(V);

        auto manhattan = [&](int a, int b)
        {
            return abs(coords[a].first - coords[b].first) + abs(coords[a].second - coords[b].second);
        };

        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                int distCost = manhattan(i, j);
                graph[i].push_back({j, distCost});
                graph[j].push_back({i, distCost});
            }
        }

        for (int i = 0; i < N; i++)
        {
            int n1 = 2 + 2 * i;
            int n2 = 2 + 2 * i + 1;
            int wcost = wormholeCost[i];

            graph[n1].push_back({n2, wcost});
            graph[n2].push_back({n1, wcost});
        }

        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);

        dist[0] = 0;

        for (int _ = 0; _ < V; _++)
        {
            int u = -1;
            int bestDist = INT_MAX;
            for (int i = 0; i < V; i++)
            {
                if (!visited[i] && dist[i] < bestDist)
                {
                    bestDist = dist[i];
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
                {
                    dist[v] = dist[u] + cost;
                }
            }
        }

        cout << dist[1] << "\n";
    }
}
