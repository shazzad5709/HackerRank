#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canReachGoalBFS(const vector<vector<int>> &grid, int N, int M, int d)
{
  int startR = N - 1;
  int startC = 0;

  if (N == 0 || M == 0)
    return false;

  if (grid[startR][startC] == 0)
    return false;

  vector<vector<bool>> visited(N, vector<bool>(M, false));
  visited[startR][startC] = true;

  queue<pair<int, int>> q;
  q.push({startR, startC});

  while (!q.empty())
  {
    auto cell = q.front();
    int r = cell.first;
    int c = cell.second;
    q.pop();

    if (grid[r][c] == 3)
    {
      return true;
    }

    if (c - 1 >= 0)
    {
      int nr = r;
      int nc = c - 1;

      if (!visited[nr][nc] && (grid[nr][nc] == 1 || grid[nr][nc] == 3))
      {
        visited[nr][nc] = true;
        q.push({nr, nc});
      }
    }

    if (c + 1 < M)
    {
      int nr = r;
      int nc = c + 1;
      if (!visited[nr][nc] && (grid[nr][nc] == 1 || grid[nr][nc] == 3))
      {
        visited[nr][nc] = true;
        q.push({nr, nc});
      }
    }

    for (int k = 1; k <= d; k++)
    {
      int nrUp = r - k;
      if (nrUp >= 0)
      {
        if (!visited[nrUp][c] && (grid[nrUp][c] == 1 || grid[nrUp][c] == 3))
        {
          visited[nrUp][c] = true;
          q.push({nrUp, c});
        }
      }

      int nrDown = r + k;
      if (nrDown < N)
      {
        if (!visited[nrDown][c] && (grid[nrDown][c] == 1 || grid[nrDown][c] == 3))
        {
          visited[nrDown][c] = true;
          q.push({nrDown, c});
        }
      }
    }
  }

  return false;
}

int main()
{
  int N, M;
  cin >> N >> M;

  vector<vector<int>> grid(N, vector<int>(M));
  for (int r = 0; r < N; r++)
  {
    for (int c = 0; c < M; c++)
    {
      cin >> grid[r][c];
    }
  }

  int low = 0;
  int high = N - 1;
  int answer = -1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (canReachGoalBFS(grid, N, M, mid))
    {
      answer = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  cout << answer << endl;

  return 0;
}