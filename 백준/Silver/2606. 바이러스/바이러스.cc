#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//1316

vector<bool> visited;
vector<vector<int>> p;
static int ans;
void bfs(int node);

int main() {
	int n;
	cin >> n;
	int e;
	cin >> e;
	
	visited.resize(n);
	p.resize(n + 1);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		p[a].push_back(b);
		p[b].push_back(a);
	}
	
	bfs(1);

	cout << ans;
	return 0;
}

void bfs(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i : p[now]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
				ans++;
			}
		}
	}
}