#include <iostream>
using namespace std;
//1176
int dp[1001];

int main() {
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] * 2 % 10007 - dp[i - 3] + 10007) % 10007;
	}

	cout << dp[n];
	return 0;
}

