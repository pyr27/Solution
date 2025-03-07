#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	vector<int> sum;
	for (int i = 1; sum.size() <= b; i++) {
		for (int j = 1; j <= i; j++) {
			sum.push_back(i);
			if (sum.size() > b) break;
		}
	}

	int ans = 0;
	for (int i = a - 1; i <= b - 1; i++) {
		ans += sum[i];
	}
	cout << ans << '\n';
	return 0;
};
