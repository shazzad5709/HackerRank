#include <bits/stdc++.h>
using namespace std;

int tsp(int source, int mask, const vector<vector<int>> &graph, vector<vector<int>> &dp);
int manhattan_distance(pair<int, int> A, pair<int, int> B);
int find_minimum_travel_for_salesman(const vector<pair<int, int>> &coordinates, int n);

int main()
{
  int num_of_test_cases = 10;
  for (int tc = 1; tc <= num_of_test_cases; tc++)
  {
    int n, x, y;

    cin >> n;

    vector<pair<int, int>> coordinates(n + 2);

    n += 2;
    cin >> x >> y;
    coordinates[0] = {x, y};
    cin >> x >> y;
    coordinates[n - 1] = {x, y};

    for (int i = 1; i < n - 1; i++)
    {
      cin >> x >> y;
      coordinates[i] = {x, y};
    }

    cout << "# " << tc << " " << find_minimum_travel_for_salesman(coordinates, n) << endl;
  }

  return 0;
}

int manhattan_distance(pair<int, int> A, pair<int, int> B)
{
  return abs(A.first - B.first) + abs(A.second - B.second);
}

int find_minimum_travel_for_salesman(const vector<pair<int, int>> &coordinates, int n)
{
  vector<vector<int>> graph(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int distance = manhattan_distance(coordinates[i], coordinates[j]);
      graph[i][j] = distance;
      graph[j][i] = distance;
    }
  }

  vector<vector<int>> dp(1 << n, vector<int>(n, -1));

  int result = tsp(0, 1, graph, dp);

  return result;
}

int tsp(int source, int mask, const vector<vector<int>> &graph, vector<vector<int>> &dp)
{
  int n = graph.size();

  if (mask == ((1 << n) - 1))
  {
    return graph[source][n - 1];
  }

  if (dp[mask][source] != -1)
  {
    return dp[mask][source];
  }

  int min_cost = INT_MAX;

  for (int loc = 1; loc < n; loc++)
  {
    if (!(mask & (1 << loc)))
    {
      int cost = graph[source][loc] + tsp(loc, mask | (1 << loc), graph, dp);
      min_cost = min(min_cost, cost);
    }
  }

  return dp[mask][source] = min_cost;
}