#include <iostream>

using namespace std;
#define N 1000000000

unsigned long long int n[101][10]= { 0 };
int num;

unsigned long long int f() {
	unsigned long long int sum = 0;

	for (int i = 2; i <= num; i++) {

		for (int j = 1; j < 10; j++) {

			if (j==1) {
				n[i][j] = (n[i - 2][j] + n[i - 1][j + 1])%N;
			}
			else if (j == 9) {
				n[i][j] = n[i - 1][j - 1];
			}
			else {
				n[i][j] = (n[i - 1][j - 1] + n[i - 1][j + 1])%N;
			}
			
			
		}
		

	}

	for (int i = 1; i < 10; i++) {
		sum = (sum + n[num][i]) % N;
	}
	
	return sum;
}

int main() {
	cin >> num;

	for (int i = 1; i < 10; i++) {
		n[1][i] = 1;
	}
	n[0][1] = 1;

	unsigned long long int ret = f();
	cout << ret%N << endl;
}