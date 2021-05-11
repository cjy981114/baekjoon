#include <iostream>
#include <vector>

using namespace std;

int n;
int a[501][2] = { 0 };
int d[501][501] = { 0 };


int f(int left, int right) {
	if (d[left][right] != -1) {
		return d[left][right];
	}
	if (left == right) {
		return 0;
	}
	int findMin = 999999999;
	for (int i = left; i < right; i++) {
		findMin = min(findMin, f(left, i)+ f(i + 1, right)+a[left][0]*a[i][1]* a[right][1]);
	}

	d[left][right] = findMin;

	return findMin;
	
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
		
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = -1;
		}
	}
	int ret = f(1,n);
	cout << ret << endl;

}