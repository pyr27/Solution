#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	int N;
	cin >> N;
	int A[50] = {};
	int B[50] = {};
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	sort(A, A + N);
	sort(B, B + N, greater<>());
	
	int S[50] = {};
	for (int i = 0; i < N; i++) {
		S[i] = A[i] * B[i];
	}
	int sum = accumulate(begin(S), end(S), 0);
	cout << sum;
	return 0;
}