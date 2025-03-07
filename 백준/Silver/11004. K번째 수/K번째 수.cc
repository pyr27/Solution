#include <iostream>
#include <vector>
using namespace std;

void merge_sort(int s, int e);
void merge(int s, int e);
static vector<int> a;
static vector<int> temp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	a = vector<int>(n+1, 0);
	temp = vector<int> (n+1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	merge_sort(1, n); //병합정렬 이용
	cout << a[k] << '\n';
	
	return 0;
}

void merge_sort(int s, int e) {
	if (e - s < 1) {
		return;
	}
	int m = (s + e) / 2;
	merge_sort(s, m);
	merge_sort(m + 1, e);
	merge(s, e);
}

void merge(int s, int e) {
	int m = (s + e) / 2;
	int i = s;
	int j = m + 1;
	int k = s;

	while (i <= m && j <= e) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= m) {
		temp[k++] = a[i++];
	}
	while (j <= e) {
		temp[k++] = a[j++];
	}
	for (int i = s; i <= e; i++) {
		a[i] = temp[i];
	}
}