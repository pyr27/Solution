#include <iostream>
#include <string>
using namespace std;
//char 로 담아보기
void hanoi(int n, char start, char end, char sub);
string addnum(string n) {
    int size = n.size();
    string num(size+1, '0');
    for(int i = n.size () - 1; i >= 0; i--){
        int x = (n[i] - '0') * 2; //n의 i번째 자릿수 * 2 (char를 int로 변환시 '0' 빼기)
        num[i + 1] += (x % 10);
        num[i] += (x / 10);
    }
    return (num[0] == '0') ? num.substr(1) : num;
}
string power(int n, string N) {
    if (n == 0) {
        int s = N.size();
        int x = (N[s - 1] - '0') - 1;
        N[s - 1] = x + '0';
        return N;}
    return power(n - 1, addnum(N));
}

int main() {
    int n;
    cin >> n;

    cout << power(n, "1") << '\n'; // long long 사용

    if (n <= 20) hanoi(n, '1', '3', '2');
}

void move(char s, char e) {
    cout << s << ' ' << e << '\n';
}

void hanoi(int n, char start, char end, char sub) {
    if (n == 1) {
        move(start, end);
        return;
    }

    hanoi(n - 1, start, sub, end); // n-1개를 보조로 이동
    move(start, end);
    hanoi(n - 1, sub, end, start); // n-1개를 목표로 이동
}
