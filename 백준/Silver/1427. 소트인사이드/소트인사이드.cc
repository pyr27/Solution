#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int n[10000] = {};
	cin >> N;
	int i = 0, cnt = 0;
	while (N != 0) {
		n[i] = N % 10;
		i++, cnt++, N /= 10;
	}
	sort(n, n + cnt, greater<>());
	for (int i = 0; i < cnt; i++) {
		cout << n[i];
	}
	return 0;
}