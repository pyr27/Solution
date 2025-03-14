#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//14502
static vector<vector<int>> v;
static int n, m;
static int ans = 0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs(vector<vector<int>> u);
void comb(int depth);
int cnt(vector<vector<int>> V);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    v.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    comb(0);

    cout << ans << '\n';
    return 0;
}

void comb(int depth) {
    if (depth == 3) {
        bfs(v);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                v[i][j] = 1; // 벽 세우기
                comb(depth + 1);
                v[i][j] = 0; // 다시 원상복구
            }
        }
    }
}
void bfs(vector<vector<int>> u) {
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (u[i][j] == 2) {
                q.push({ i, j });
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || u[nx][ny] != 0) continue;

            u[nx][ny] = 2;
            q.push({ nx, ny });
        }
    }

    ans = max(ans, cnt(u));
}

int cnt(vector<vector<int>> V) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (V[i][j] == 0) count++;
        }
    }
    return count;
}
