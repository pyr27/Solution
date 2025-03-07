#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<long> Sum(n, 0);
	vector<long> Cnt(m, 0);
	long ans = 0;

	cin >> Sum[0];
	Sum[0] %= m;
	if (Sum[0] == 0) ans++;
	Cnt[Sum[0]]++;

	for (int i = 1; i < n; i++) {
		int temp = 0;
		cin >> temp;
		Sum[i] = (Sum[i - 1] + temp) % m;

		if (Sum[i] == 0) ans++;
		Cnt[Sum[i]]++;
	}
	 
	for (int i = 0; i < m; i++) {
		if (Cnt[i] > 1) {
			ans += (Cnt[i] * (Cnt[i] - 1)) / 2;
		}
	}

	cout << ans << '\n';
};
