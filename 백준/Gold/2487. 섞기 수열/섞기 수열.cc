#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int n;
    cin >> n;

    vector<int> card(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        cin >> card[i];
    }

    vector<int> cycles;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int length = 0;
            int t = i;

            while (!visited[t]) {
                visited[t] = true;
                t = card[t];
                length++;
            }

            cycles.push_back(length);
        }
    }


    int result = cycles[0];
    for (int i = 1; i < cycles.size(); i++) {
        result = lcm(result, cycles[i]);
    }

    cout << result << '\n';
    return 0;
}
