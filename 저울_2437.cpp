#include <iostream>
#include <algorithm>
using namespace std;

int a[1001] = { 0 };

int main() {
	int n;
	cin >> n;

	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	if (a[0] != 1) {
		cout << 1 << endl;
		return 0;
	}
	
	int sum = 1;
	for (int i = 1; i < n; i++) {
		if (sum + 1 < a[i]) {
			break;
		}
		else
			sum += a[i];
	}

	int num = sum + 1;
	cout << num << endl;
	return 0;
}