#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	
	int x = 0;
	cin >> x;

	int sum = 0;
	int a = 1;
	while (x > sum) {
		sum += a;
		a += 1;
	}

	a--;
	
	int num = sum - x;
	if (x == 1) {
		cout << 1 << '/' << 1 << '\n';
	}
	else {
		if (a % 2 == 0) {
			cout << a - num << '/' << 1 + num << '\n';
		}
		else {
			cout << 1 + num << '/' << a - num << '\n';
		}
	}
}