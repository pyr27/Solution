#include <iostream>
#include <vector>
using namespace std;
//1057
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, a, b;
	cin >> N >> a >> b;

	int x, y;
	int ans = 0;

	while (a != b) {
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		ans++;
	}
	
	cout << ans << '\n';
};