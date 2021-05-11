#include<iostream>

using namespace std;

int main() {
	int r, n, m;
	int cnt = 0;
	cin >> r >> n >> m;
	while (1) {
		if ((n % 2)==0) {
			n = n / 2;
		}
		else {
			n = n / 2 + 1;
		}
		if ((m % 2)==0) {
			m = m / 2;
		}
		else {
			m = m / 2 + 1;
		}

		if (n == m) {
			break;
		}
		else {
			cnt++;
		}
	}
	cout << cnt+1 << endl;
}