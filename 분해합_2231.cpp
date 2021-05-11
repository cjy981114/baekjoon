#include <iostream>

using namespace std;

int num;
int n[1000001] = { 0 };

int makeOne(int n) {
	int sum = 0;
	while (n/10) {
		sum += n % 10;
		n = n / 10;
	}
	sum += n;
	return sum;
	
}

int main() {


	cin >> num;

	for (int i = 1; i <= num; i++) {
		int oneSum = makeOne(i);
		if (n[oneSum + i] != 0) {
			n[oneSum + i] = min(i, n[oneSum + i]);
		}
		else {
			n[oneSum + i] = i;
		}
	}

	cout << n[num] << endl;
}