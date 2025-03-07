#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N;
	cin >> N;

	int y_cnt = 0;
	int m_cnt = 0;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;

		y_cnt += (t / 30 + 1) * 10;
		m_cnt += (t / 60 + 1) * 15;

	}

	if (y_cnt < m_cnt) {
		cout << "Y " << y_cnt << '\n';
	}
	else if (y_cnt > m_cnt) {
		cout << "M " << m_cnt << '\n';
	}
	else {
		cout << "Y M " << y_cnt << '\n';
	}

}