#include <iostream>
#include <cmath>
using namespace std;

int n;
int d[100001] = { 0 };

int f(int num) {
	if (num == 1) {
		d[num] = 1;
		return d[num];
	}
	if (d[num] != 0) {
		return d[num];
	}

	int sq = sqrt(num);
	d[num] = 999999;

	for (int i = sq; i >= 1; i--) {
		int po = pow(i, 2);
		if (num != po) {
			d[num] = min(d[num], f(po) + f(num - po));
		}
		else {
			return d[num] = 1;
		}
	}

	return d[num];
}

int main() {
	cin >> n;

	int ret = f(n);

	cout << ret << endl;
}