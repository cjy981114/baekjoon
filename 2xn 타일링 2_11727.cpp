#include <iostream>

using namespace std;

int main() {

	int n;
	int d[1001] = {0};
	int ret = 0;
	cin >> n;

	d[0] = d[1] = 1;

	if (n == 1) {
		ret = d[1];
	}
	else {
		for (int i = 2; i <= n; i++) {
			d[i] = (d[i - 2] * 2)%10007 + d[i - 1];
			d[i] %= 10007;
		}
		ret = d[n];
	}

	cout << ret << endl;
}