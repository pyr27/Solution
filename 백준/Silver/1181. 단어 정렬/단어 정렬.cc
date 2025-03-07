#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool comp(string a, string b) {
	if (a.length() != b.length()) return a.length() < b.length();
	else if (a.length() == b.length()) return a < b;
}
int main() {
	int N;
	cin >> N;
	string word[20000];
	for (int i = 0; i < N; i++) { cin >> word[i]; }

	sort(word, word+N, comp);

	for (int i = 0; i < N; i++) {
		if (word[i] == word[i + 1]) continue;
		cout << word[i] << endl;
	}
	return 0;
}