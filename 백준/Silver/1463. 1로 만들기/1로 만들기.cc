#include <iostream>
using namespace std;
//1463
int dp[1000001];

int main() {
	int n;
	cin >> n;

	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		int temp = 1000001;
		if (i % 3 == 0) {
			dp[i] = min(temp, dp[i / 3] + 1);
			temp = dp[i];
		}

		if (i % 2 == 0) {
			dp[i] = min(temp, dp[i / 2] + 1);
			temp = dp[i];
		}
		
		dp[i] = min(temp, dp[i - 1] + 1);

	}

	cout << dp[n];
	return 0;
}
