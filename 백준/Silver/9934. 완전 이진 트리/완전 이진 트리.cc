#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> num;
vector<int> ans[10];
//완전이진트리

void insertTree(int depth, int first, int last) {
    if (first > last) return;
    int mid = (first + last) / 2;

    ans[depth].push_back(num[mid]);

    insertTree(depth + 1, first, mid - 1);
    insertTree(depth + 1, mid + 1, last);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k;
    cin >> k; //깊이
    int n = pow(2, k) - 1; //노드개수
    num.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    insertTree(0, 0, n - 1);

    for (int i = 0; i < k; i++) {
        for (auto a : ans[i]) {
            cout << a << ' ';
        }
        cout << '\n';
    }
    return 0;
}