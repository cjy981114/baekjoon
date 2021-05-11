#include <iostream>

using namespace std;

int n, m;
int d[31][31] = { 0 };
int main() {
	int tc;
	cin >> tc;

	for (int i = 1; i <= 30; i++) {
		d[1][i] = i;
	}

	while (tc) {
		cin >> n >> m;
		if (d[n][m] != 0) {
			cout << d[n][m] << endl;
			--tc;
			continue;
		}

		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= m; j++) {
				if (i == j) {
					d[i][j] = 1;
					continue;
				}
				d[i][j] = d[i - 1][j - 1] + d[i][j - 1];
			}
		}
		cout << d[n][m] << endl;
		--tc;
	}
	
}