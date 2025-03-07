#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long a, b;
	cin >> a >> b;

    long A[10000001];

    for (long i = 2; i < 10000001; i++) {
        A[i] = i;
    }

    for (long i = 2; i <= sqrt(10000001); i++) {
        if (A[i] == 0) {
            continue;
        }
        for (long j = i + i; j < 10000001; j += i) {
            A[j] = 0;
        }
    }

    long ans = 0;

    for (long i = 2; i < 10000001; i++) {
        if (A[i] != 0) {
            long temp = A[i];

            while ((double)A[i] <= (double)b/(double)temp) {
                if ((double)A[i] >= (double)a / (double)temp) {
                    ans++;
                }
                temp *= A[i];
            }

        }
    }

    cout << ans << '\n';
    return 0;
}