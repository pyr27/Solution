#include <iostream>
#include <string>
#include <vector>
using namespace std;
//1316

vector<int> word;
bool wordCheck(int t);

int main() {
	int n;
	cin >> n;
	string w;
	
	int ans = 0;
	while (n--) {
		cin >> w;
		int s = w.size();
		word.clear();
		if (s == 1) {
			ans++;
		}
		else {
			word.push_back(w[0] - '0');
			bool isGroup = true;
			for (int i = 1; i < s; i++) {
				int t = w[i] - '0';
				if (word.back() == t) {
					continue;
				}
				if (!wordCheck(t)) {
					isGroup = false;
					break;
				}
				word.push_back(t);
			}
			if (isGroup) ans++;
		}
	}

	cout << ans;
	return 0;
}

bool wordCheck(int t) {
	for (int i = 0; i < word.size(); i++) {
		if (t == word[i]) { return false; }
	}
	return true;
}