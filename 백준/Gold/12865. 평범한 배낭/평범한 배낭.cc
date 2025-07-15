#include <iostream>
#include <vector>
using namespace std;
//12865

int main() {
	int n, k;
	cin >> n >> k;
	
	int p[100][2];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> p[i][j];
		}
	}

	vector<vector<int>> P;
	P.resize(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int w = 0; w <= k; w++) {
			if (p[i][0] <= w) {
				P[i][w] = max(P[i - 1][w], p[i][1] + P[i - 1][w - p[i][0]]);
			}
			else {
				P[i][w] = P[i - 1][w];
			}
		}
	}

	cout << P[n][k];
	return 0;
}

