#include <iostream>
#include <cmath>

using namespace std;

int n;
int a[2][100001] = { 0 };


int dup[100001] = { 0 };
int ddown[100001] = { 0 };

int f(int num) {
	dup[1] = a[0][1];
	ddown[1] = a[1][1];

	for (int i = 2; i <= n; i++) {
		dup[i] = max(ddown[i - 1] + a[0][i], ddown[i - 2] + a[0][i]);
		ddown[i] = max(dup[i - 1] + a[1][i], dup[i - 2] + a[1][i]);
	}

	return max(dup[n], ddown[n]);
}

int main() {
	int tc;
	cin >> tc;

	while (tc > 0) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}

		int ret = f(1);
		cout << ret << endl;
		--tc;
	}
}