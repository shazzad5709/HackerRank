#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int manhattan_distance(pair<int, int> A, pair<int, int> B)
{
  return abs(A.first - B.first) + abs(A.second - B.second);
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, x, y, w;
    cin >> n;
    vector<pair<int, int>> c(2 * n + 2);
    vector<int> wc(n, 0);

    cin >> x >> y;
    c[0] = {x, y};

    cin >> x >> y;
    c[1] = {x, y};
    int j = 0;

    for (int i = 1; i < n + 1; i++)
    {
      cin >> x >> y;
      c[i++] = {x, y};
      cin >> x >> y;
      c[i] = {x, y};

      cin >> wc[j++];
    }
  }
}