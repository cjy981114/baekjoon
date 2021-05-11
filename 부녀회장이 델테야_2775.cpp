#include <iostream>

using namespace std;

int main() {
	int n, k;
	int a[15][15] = { 0 };

	int tc;
	cin >> tc;
	for (int i = 1; i <= 14; i++) {
		a[0][i] = i;
	}
	while (tc) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				a[i][j] = a[i - 1][j] + a[i][j - 1];
			}
		}

		cout << a[n][k] << endl;
		--tc;
	}
}