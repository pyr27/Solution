#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void DFS(int num, int N);
bool isPrime(int num);
static int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

}

void DFS(int num, int N) {
	if (N == n) {
		if (isPrime(num)) {
			cout << num << '\n';
		}
		return;
	}
	int i = 1;
	while (i < 10) {
		if (isPrime(num * 10 + i)) {
			DFS(num * 10 + i, N + 1);
		}
		i += 2;
	}
}

bool isPrime(int num) {
	if (num == 2) return true;

	for (int i = 3; i <= sqrt(num); i+=2) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
