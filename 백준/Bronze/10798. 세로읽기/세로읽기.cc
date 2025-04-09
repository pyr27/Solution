#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> words(5);
	int Max = 0;
	for (int i = 0; i < 5; i++) {
		cin >> words[i];

		Max = (Max > words[i].size()) ? Max : words[i].size();
	}

	string ans = "";
	for (int i = 0; i < Max; i++) {
		for (int j = 0; j < 5; j++) {
			if (i < words[j].size()) {
				ans.push_back(words[j][i]);
			}
			else continue;
		}
	}


	cout << ans;
	return 0;
}