#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    vector<int> D(41, 0);

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        D[0] = 1;
        D[1] = 1;

        for (int i = 2; i <= N; i++) {
            D[i] = D[i - 1] + D[i - 2];
        }

        if (N == 0) {
            cout << "1 0" << '\n';
        }
        else if (N == 1) {
            cout << "0 1" << '\n';
        }
        else {
            cout << D[N - 2] << ' ' << D[N - 1] << '\n';
        }
    }
    return 0;
}