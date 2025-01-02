#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

static const int INF = INT_MAX;

int n;
int gate[3];
int people[3];
int sumF;

static int dp[101][11][11][11];

int solveMemo(int index, int p0, int p1, int p2) {
    if (p0 + p1 + p2 == 0) {
        return 0;
    }
    if (index > n) {
        return INF;
    }
    int &res = dp[index][p0][p1][p2];
    if (res != -1) {
        return res;
    }

    int best = solveMemo(index + 1, p0, p1, p2);

    if (p0 > 0) {
        int cost = abs(gate[0] - index) + 1;
        int rec = solveMemo(index + 1, p0 - 1, p1, p2);
        if (rec != INF) {
            best = min(best, cost + rec);
        }
    }

    if (p1 > 0) {
        int cost = abs(gate[1] - index) + 1;
        int rec = solveMemo(index + 1, p0, p1 - 1, p2);
        if (rec != INF) {
            best = min(best, cost + rec);
        }
    }

    if (p2 > 0) {
        int cost = abs(gate[2] - index) + 1;
        int rec = solveMemo(index + 1, p0, p1, p2 - 1);
        if (rec != INF) {
            best = min(best, cost + rec);
        }
    }

    res = best;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> gate[i];
    }
    sumF = 0;
    for (int i = 0; i < 3; i++){
        cin >> people[i];
        sumF += people[i];
    }

    memset(dp, -1, sizeof(dp));

    int ans = solveMemo(1, people[0], people[1], people[2]);
    cout << ans << "\n";
    return 0;
}
