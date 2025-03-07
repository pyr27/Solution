#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void DFS(int node);
void BFS(int node);
vector<vector<int>> A;
vector<bool> visited;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, start;
	cin >> n >> m >> start;

	A.resize(n+1);
	//인접리스트 저장
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	int i = 1;
	while (i <= n) {
		sort(A[i].begin(), A[i].end());
		i++;
	}
	visited = vector<bool>(n+1, false);
	DFS(start);
	cout << '\n';
	fill(visited.begin(), visited.end(), false);
	BFS(start);
	cout << '\n';
}

void DFS(int node) {
	
	cout << node << ' ';

	visited[node] = true;

	for (int i : A[node]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}

void BFS(int node) {
	queue<int> myq;
	myq.push(node);
	visited[node] = true;
	while (!myq.empty()) {
		int now = myq.front();
		myq.pop();
		cout << now << ' ';
		for (int i : A[now]) {
			if (!visited[i]) {
				visited[i] = true;
				myq.push(i);
			}
		}
	}
}