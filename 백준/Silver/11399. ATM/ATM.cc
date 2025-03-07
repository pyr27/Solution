#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* array = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}

	sort(array, array + N);
	
	int ans = 0;
	int i = 0;
	while (N > 0) {
		ans += array[i] * N;
		N--;
		i++;
	}
	
	cout << ans << '\n';
}