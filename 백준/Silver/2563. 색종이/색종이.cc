#include <iostream>
#include <vector>
using namespace std;
//2563

int main() {

	int t = 0;
	cin >> t;

	int x, y;
	vector<vector<int>> area(101, vector<int>(101, 0));
	while (t--) {
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				area[i][j] = 1;
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (area[i][j] == 1) {
				ans++;
			}
		}
	}
	
	cout << ans;
	return 0;
}