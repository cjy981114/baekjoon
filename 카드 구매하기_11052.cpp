#include <iostream>

using namespace std;
int n;
int a[1001] = {0};
int d[1001] = { 0 };
int main() {
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	d[1] = a[1];
	for (int i = 2; i <= n; i++) {
		d[i] = a[i];
		for (int j = i - 1; j >= i / 2; j--) {
			d[i] = max(d[i], d[j] + d[i - j]);
		}
	}
	
	cout << d[n] << endl;
}