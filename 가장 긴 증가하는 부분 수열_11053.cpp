#include <iostream>
using namespace std;


int arr[1001] = { 0 };
int num = 0;
int d[1001] = { 0};

int f(int n) {
	int ret = d[n];

	if (ret != 0) {
		return ret;
	}

	if (n == num) {
		d[n] = 1;
		return d[n];
	}

	int mmax = 0;
	for (int i = n + 1; i <= num; i++) {
		if (arr[n] < arr[i]) {
			mmax= max(mmax, f(i)+1);
		}
	}
	if (mmax == 0)
		d[n] = 1;
	else
		d[n] = mmax;
	
	return d[n];
}

int main() {
	cin >> num;

	for (int i = 1; i <= num; i++) {
		cin >> arr[i];
	}

	int ret = f(0);
	cout << ret-1 << endl;
}