#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	string st;
	getline(cin, st);
	stringstream ss(st);

	string words;
	int cnt=0;
	while (ss >> words) {
		cnt++;
	};
	cout << cnt << '\n';

	return 0;
}