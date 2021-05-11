#include <iostream>

using namespace std;
bool f(int num) {
	if (num == 1)
		return false;
	for (int i = 2; i < num; i++) {
		if (num%i== 0)
			return false;
	}
	return true;
}

int main() {
	int n;
	int cnt = 0;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (f(a)) {
			cnt++;
		}
	}

	cout << cnt << endl;
}