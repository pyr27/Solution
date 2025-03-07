#include <iostream>
using namespace std;
int main() {
	long int N = 0, F = 0;
	cin >> N;
	cin >> F;
	
	if (N >= 100 || N <= 2000000000) {
		int n = N / 100;
		int num = n * 100;

		for (int i = 0; i < 100;i++) {
			while ((num + i) % F != 0)
				i++;
			if((num+i)%F == 0){
				if (i < 10) {
				cout << "0" << i << endl;
				break;
				}
				else {
				cout << i << endl;
				break;
				}
			}
		}
	}
	return 0;
}