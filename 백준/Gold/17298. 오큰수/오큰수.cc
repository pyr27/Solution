#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	stack<int> myStack;
	int* ans = new int[n];
	myStack.push(0);
	for (int i = 1; i < n; i++) {
		while (!myStack.empty() && a[myStack.top()] < a[i]) {
			ans[myStack.top()] = a[i];
			myStack.pop();
		}
		myStack.push(i);
	}
	while (!myStack.empty()) {
		ans[myStack.top()] = -1;
		myStack.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}