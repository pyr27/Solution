#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int node);
static vector<bool> visited;
static vector<int> ans;
static vector<vector<int>> cptnum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	cptnum.resize(n + 1);
	ans.resize(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cptnum[a].push_back(b);
	}
	
	visited.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		fill(visited.begin(), visited.end(), false);
		BFS(i);
	}

	int Max = 0;
	for (int i = 1; i <= n; i++) {
		Max = max(Max, ans[i]);
	}


	for (int i = 1; i <= n; i++) {
		if (ans[i] == Max) {
			cout << i << ' ';
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
		for (int i : cptnum[now]) {
			if (visited[i] == false) {
				visited[i] = true;
				ans[i]++;
				myq.push(i);
			}
		}
	}
}