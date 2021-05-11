#include <iostream>

using namespace std;

int tc;
int n;
int a[501] = { 0 };
int d[501][501] = { 0 };
int sum[501] = {0};

int f(int left, int right) {
	if (d[left][right] != -1) {
		return d[left][right];
	}

	if (left == right) {
		d[left][right] = 0;
		return d[left][right];
	}
	int findMin = 999999999;
	for (int i = left; i < right; i++) {
		int l = f(left, i);
		int r = f(i + 1, right);
		findMin = min(findMin, l+r+sum[right] - sum[left-1]);
	}
	
	d[left][right] = findMin;

	return findMin;
}


int main() {

	cin >> tc;
	while (tc > 0) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];

			sum[i] = sum[i - 1] + a[i];
		}
		for (int i = 1; i <= n; i++) {	
			for (int j = 1; j <= n; j++) {
				d[i][j] = -1;
			}
		}
		int ret = f(1, n);
		cout << ret<< endl;
		
		tc--;
	}
}