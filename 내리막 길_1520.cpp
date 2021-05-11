#include <iostream>

using namespace std;
int r, l;

int a[501][501] = { 0 };
int d[501][501] = { 0 };

int f(int x, int y) {

	if (d[x][y] != -1) {
		return d[x][y];
	}

	if (x == r && y == l) {
		d[x][y] = 1;
		return 1;
	}


	int test[4][2] = { {x - 1,y}, {x + 1, y}, {x,y - 1}, {x,y+1} };
	
	int sum = 0;

	for (int i = 0; i < 4; i++) {
		if (a[test[i][0]][test[i][1]] != 0 && a[x][y] > a[test[i][0]][test[i][1]]) {
			sum+=f(test[i][0], test[i][1]);
		}
	}
	d[x][y] = sum;
	return sum;
}


int main() {
	cin >> r >> l;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= l; j++) {
			cin >> a[i][j];
			d[i][j] = -1;
		}
	}

	int ret = f(1, 1);
	cout << ret << endl;
}