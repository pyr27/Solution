#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> myq;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		myq.push(x);
	}

	int sum = 0;
	while (myq.size() != 1) {
		int d1 = myq.top();
		myq.pop();
		int d2 = myq.top();
		myq.pop();

		sum += (d1 + d2);
		myq.push(d1 + d2);
	}

	cout << sum << '\n';
}