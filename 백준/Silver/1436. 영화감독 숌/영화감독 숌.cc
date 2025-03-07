#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, cnt = 0;
	cin >> N;
	string ans;
	int num = 666;
	
	while (1) {
		ans = to_string(num);
		if (ans.find("666") != -1) {
			cnt++;
			if (cnt == N) {
				cout << ans;
				break;
			}
		}
		num++;
	}

}