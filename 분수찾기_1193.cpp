#include <iostream>

using namespace std;


int main() {
	int n;
	cin >> n;

	int p = 1;
	int sum = 0;
	while (sum < n) {
		sum = sum + p;
		p++;
	}

	int minus = sum - n;
	p -= 1;
	if (p % 2 == 1) {
		cout << 1 + minus << "/" << p - minus << endl;
	}
	else {
		cout << p - minus << "/" << 1 + minus << endl;
	}

	return 0;
}