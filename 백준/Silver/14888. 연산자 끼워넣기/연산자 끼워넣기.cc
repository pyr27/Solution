#include <iostream>
#include <vector>
using namespace std;
//14888

int oper[4];
int Min = 1e9;
int Max = -1e9;
int n;
int num[11];

void dfs(int depth, int cur) {
	if (depth == n - 1) {
		if (cur > Max) Max = cur;
		if (cur < Min) Min = cur;
	}
	if (oper[0] > 0) {
		oper[0]--;
		dfs(depth + 1, cur + num[depth + 1]);
		oper[0]++;
	}
	if (oper[1] > 0) {
		oper[1]--;
		dfs(depth + 1, cur - num[depth + 1]);
		oper[1]++;
	}
	if (oper[2] > 0) {
		oper[2]--;
		dfs(depth + 1, cur * num[depth + 1]);
		oper[2]++;
	}
	if (oper[3] > 0) {
		oper[3]--;
		dfs(depth + 1, cur / num[depth + 1]);
		oper[3]++;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	} 

	dfs(0, num[0]);

	cout << Max << '\n' << Min;
	return 0;
}

