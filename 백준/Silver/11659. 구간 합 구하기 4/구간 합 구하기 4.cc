#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m; //n = 수의 개수, m = 합 구하는 횟수
	cin >> n >> m;

	int sum[100001];
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		sum[i] = sum[i-1] + temp;
	}
	int i, j; //i 시작 j 끝
	for (int a = 0; a < m; a++) {
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << '\n';
	}
}