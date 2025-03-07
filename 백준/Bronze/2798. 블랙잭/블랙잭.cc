#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	vector<int> card(n);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	sort(card.begin(), card.end());

	int sum = 0;
	int max_sum = 0;
	for (int x = 0; x < n - 2; x++) {
		for (int y = x + 1; y < n - 1; y++) {
			for (int z = y + 1; z < n; z++) {
				sum = card[x] + card[y] + card[z];
				if (sum > m) break;
				max_sum = max(max_sum, sum);
			}
		}
	}

	cout << max_sum << '\n';
	return 0;
};