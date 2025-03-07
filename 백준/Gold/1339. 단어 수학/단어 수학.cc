#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    int alpha[26] = { 0 };

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;

        int v = 1;
        for (int j = word.size() - 1; j >= 0; j--) {
            alpha[word[j] - 'A'] += v;
            v *= 10;
        }
    }

    sort(alpha, alpha+26, greater<int>());

    int ans = 0;
    int num = 9;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] == 0) break;
        ans += alpha[i] * num--;
    }

    cout << ans << '\n';
    return 0;
}
