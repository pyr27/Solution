#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//16234

static int N, L, R;
vector<vector<int>> land;
vector<vector<bool>> visited;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1 , 0, -1 };

int flag = 0;

void cal_move(vector<pair<int, int>> c, int total) {
    int value = total / c.size();

    for (int k = 0; k < c.size(); k++) {
        int x = c[k].first;
        int y = c[k].second;
        land[y][x] = value;
    }
    
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> union_c;
    q.push({ x, y });
    visited[y][x] = true;
    union_c.push_back({ x, y });

    int total = land[y][x];

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = xx + dx[d];
            int ny = yy + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx]) continue;
            
            int dif = land[yy][xx] - land[ny][nx];
            if (abs(dif) < L || abs(dif) > R) continue;
                
            visited[ny][nx] = true;
            q.push({ nx, ny });
            union_c.push_back({ nx, ny });
            total += land[ny][nx];
        }
    }
    
    if (union_c.size() > 1) {
        cal_move(union_c, total);
    }
    else {
        flag++;
    }
}
int main() {
    cin >> N >> L >> R;

    land.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> land[i][j];
        }
    }

    int ans = 0;
    while (ans <= 2000) {
        flag = 0;
        visited.assign(N, vector<bool>(N, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) bfs(j, i);
            }
        }
        
        if (flag == (N * N)) break;
        ans++;

    }

    cout << ans;
    return 0;
}
