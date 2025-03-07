#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int testN;
	for (int i = 0; i < 3; i++) {
		cin >> testN;

		long long sum = 0;
		int flow = 0;
		for (int j = 0; j < testN; j++) {
			long long x;
			cin >> x;
			long long temp = sum;
			sum += x;
			if (x > 0 && temp > 0 && sum < 0) flow++;
			if (x < 0 && temp < 0 && sum > 0) flow--;
			
		}

		if (flow == 0) {
			if (sum == 0) cout << 0 << '\n';
			else cout << (sum > 0 ? '+' : '-') << '\n';
		}
		else {
			cout << (flow > 0 ? '+' : '-') << '\n';
		}
	}

	return 0;
}