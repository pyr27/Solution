#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	int start_index = 1, end_index = 1;
	int sum = 1;
	
	int ans = 1;
	while (end_index != N) {
		if (sum == N) {
			ans++;
			end_index++;
			sum += end_index;
		}
		else if (sum > N) {
			sum = sum - start_index;
			start_index++;
		}
		else {
			end_index++;
			sum += end_index;
		}
	}

	cout << ans << '\n';
}