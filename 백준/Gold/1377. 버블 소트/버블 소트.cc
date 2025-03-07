#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < a[i].second - i) {
			ans = a[i].second - i;
		}
	}

	cout << ans + 1 << '\n';
}
