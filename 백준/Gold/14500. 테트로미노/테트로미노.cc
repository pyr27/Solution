#include <iostream>
#include <vector>
using namespace std;
//14500
int findMax(vector<vector<int>>& v, pair<int, int> t);

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> tetro(n, vector<int>(m,1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tetro[i][j];
		}
	}


	int Max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp = findMax(tetro, {i, j});
			Max = max(temp, Max);
		}
	}

	cout << Max;
	return 0;
}

int findMax(vector<vector<int>>& v, pair<int, int> t) {

	int N = v.size();
	int M = v[0].size();

	vector<vector<pair<int, int>>> T = {
		{ {0, 0}, {0, 1}, {1, 0}, {1, 1} }, // ㅁ
		{ {0, 0}, {0, 1}, {0, 2}, {0, 3} }, // ㅣ
		{ {0, 0}, {1, 0}, {2, 0}, {3, 0} }, // ㅡ
		{ {0, 0}, {1, 0}, {2, 0}, {2, 1} }, // L
		{ {2, 0}, {1, 1}, {2, 1}, {0, 1} }, // L 좌 
		{ {0, 0}, {1, 0}, {1, 1}, {1, 2} }, // ㄴ
		{ {1, 0}, {1, 1}, {1, 2}, {0, 2} }, // ㄴ 좌
		{ {0, 0}, {0, 1}, {0, 2}, {1, 2} }, // ㄱ
		{ {0, 0}, {1, 0}, {0, 1}, {0, 2} }, // ㄱ 우
		{ {0, 0}, {1, 0}, {2, 0}, {0, 1} }, // L 위
		{ {0, 0}, {0, 1}, {1, 1}, {2, 1} }, // L 위&좌
		{ {1, 0}, {1, 1}, {0, 1}, {0, 2} }, // Z 우
		{ {0, 0}, {0, 1}, {1, 1}, {1, 2} }, // Z 
		{ {1, 0}, {0, 1}, {1, 1}, {2, 0} }, // Z 우회전
		{ {0, 0}, {1, 0}, {1, 1}, {2, 1} }, // Z 좌회전
		{ {0, 0}, {1, 0}, {2, 0}, {1, 1} }, // ㅏ
		{ {0, 1}, {1, 0}, {1, 1}, {2, 1} }, // ㅓ
		{ {0, 0}, {0, 1}, {0, 2}, {1, 1} }, // ㅜ
		{ {0, 1}, {1, 1}, {1, 0}, {1, 2} } // ㅗ
	};

	int max_sum = 0;

	for (auto& shape : T) {
		int sum = 0;
		bool valid = true;
		for (auto& d : shape) {
			int I = t.first + d.first;
			int J = t.second + d.second;

			if (I < 0 || I >= N || J < 0 || J >= M) {
				valid = false;
				break;
			}
			else {
				sum += v[I][J];
			}
		}
		if (valid) max_sum = max(max_sum, sum);
	}


	return max_sum;
}