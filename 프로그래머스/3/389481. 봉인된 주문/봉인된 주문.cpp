#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 문자열 -> 숫자
unsigned long long strtonum(const string& w) {
    unsigned long long m = 0;
    for (int i = 0; i < w.size(); i++) {
        int c = w[i] - 'a' + 1;
        m = m * 26 + c;
    }
    return m;
}

// 숫자 -> 문자열
string numtostr(unsigned long long num) {
    string result = "";
    while (num > 0) {
        num--;
        result = char('a' + (num % 26)) + result;
        num /= 26;
    }
    return result;
}

string solution(long long n, vector<string> bans) {
    // 금지 문자열을 숫자로 변환해서 정렬
    vector<unsigned long long> ban_nums;
    for (string& b : bans) {
        ban_nums.push_back(strtonum(b));
    }
    sort(ban_nums.begin(), ban_nums.end());

    long long adjusted_n = n;
    int idx = 0;

    while (idx < ban_nums.size()) {
        if (ban_nums[idx] <= adjusted_n) {
            adjusted_n++;
            idx++;
        } else {
            break;
        }
    }

    return numtostr(adjusted_n);
}
