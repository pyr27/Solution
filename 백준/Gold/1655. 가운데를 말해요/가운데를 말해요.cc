#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	priority_queue<int> maxHeap; //desc
	priority_queue<int, vector<int>, greater<int>> minHeap; //asc
	for (int i = 0; i < t; i++) {
		int N;
		cin >> N;
		
		//최소힙은 최대힙 크기보다 작을때만 원소 추가
		if (minHeap.size() < maxHeap.size()) {
			minHeap.push(N);
		}
		else {
			maxHeap.push(N);
		}

		if (!maxHeap.empty() && !minHeap.empty() 
			&& (maxHeap.top() > minHeap.top())) {
			int a, b;
			a = maxHeap.top();
			b = minHeap.top();
			maxHeap.pop();
			minHeap.pop();

			minHeap.push(a);
			maxHeap.push(b);
		}
		
		cout << maxHeap.top() << "\n";
	}
}