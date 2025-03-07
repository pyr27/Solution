#include <iostream>
#include <algorithm>
using namespace std;

int N, M, A[1000000], x;

void binary_search(int x) {
	int first = 0;
	int last = N - 1;
	while (first <= last) {
		int Mid = (first + last) / 2;
		if (x == A[Mid]) {
			cout << 1 << '\n';
			return;
		}
		else if (x < A[Mid]) {
			last = Mid - 1;
		}
		else if (x > A[Mid]) {
			first = Mid + 1;
		}
	}
	cout << 0 << '\n';
	
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A+N);

	cin >> M;
	for (int j = 0; j < M; j++) {
		cin >> x;
		binary_search(x);

	}

	return 0;
}
