#include <iostream>

using namespace std;

int n, m;
int a[301][301] = { 0 };
int d[301][301] = { 0 };
int f(int row, int col) {

	if (row == n+1 || col == m+1)
		return 0;

	if (d[row][col] != 0)
		return d[row][col];
	
	return d[row][col]=a[row][col]+max(f(row, col + 1), f(row + 1, col));

}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		 

		}
	}
	int ret = f(1, 1);
	cout << ret << endl;

}