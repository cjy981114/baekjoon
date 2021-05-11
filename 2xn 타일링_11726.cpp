#include <iostream>
using namespace std;

int n;
int d[1001] = { 0 };
int f(int num) {
	if (num == 1)
		return 1;

	for (int i = 2; i <= num; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 10007;
	}

	return d[num]%10007;
}
int main() {
	cin >> n;

	d[0] = d[1] = 1;
	
	int ret = f(n);
	cout << ret%10007 << endl;
}