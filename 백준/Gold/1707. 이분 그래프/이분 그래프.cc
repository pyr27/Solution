#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<vector<int>> A; //인접리스트
static vector<int> Chk; //이분배열체크
static vector<int> visited; //방문기록
static bool BG; //Bipartite Graph 이분그래프
void DFS(int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int V, E;
        cin >> V >> E; //정점개수 V 간선개수 E
        A.resize(V + 1);
        visited.resize(V + 1);
        Chk.resize(V + 1);
        BG = true;

        for (int j = 0; j < E; j++) {
            int s, e;
            cin >> s >> e; //정점 번호
            A[s].push_back(e);
            A[e].push_back(s);
        }
        
        for (int j = 1; j <= V; j++) {
            if (BG) {
                DFS(j);
            }
            else {
                break;
            }
        }
        if (BG) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }

        //테스트케이스 초기화
        for (int j = 0; j <= V; j++) {
            A[j].clear();
            visited[j] = false;
            Chk[j] = 0;
        }
    }

}

void DFS(int node) {
    visited[node] = true;
    for (int i : A[node]) {
        if (!visited[i])
        {
            Chk[i] = (Chk[node] + 1) % 2;
            DFS(i);
        }
        else if (Chk[i] == Chk[node]) {
            BG = false;
        }
    }
}