#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	char ch;
	string letter;

	int ans = 0;

	while (cin.get(ch)) {
		if (ch == '#') {
			break;
		}

		if (ch == '\n') {
			if (!letter.empty()) {
				for (int i = 0; i < letter.size(); i++) {
					if (letter[i] == 'A' || letter[i] == 'a' ||
						letter[i] == 'E' || letter[i] == 'e' ||
						letter[i] == 'I' || letter[i] == 'i' ||
						letter[i] == 'O' || letter[i] == 'o' ||
						letter[i] == 'U' || letter[i] == 'u') {
						ans += 1;
					}
				}
				cout << ans << '\n';
				ans = 0;
				letter.clear();
			}
		}
		else {
			letter += ch;
		}
	}

}