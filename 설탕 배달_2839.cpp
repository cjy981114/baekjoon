#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = 999999999;
	
	int left = n / 5;

	for (int i = left; i >= 0; i--) {
		if ((n - (i * 5)) % 3 == 0) {
			cnt = min(cnt, i + ((n - (i * 5)) / 3));
		}
	}

	if (cnt == 999999999) {
		cout << -1 << endl;
	}
	else {
		cout << cnt << endl;
	}
	
}