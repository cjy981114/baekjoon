#include <iostream>

using namespace std;


int f(int num) {
	if (num == 1)
		return 0;
	for (int i = 2; i < num; i++) {
		if (num % i == 0)
			return 0;
	}
	return 1;
}
int main() {
	int m, n;
	int sum = 0;
	int ret = 0;
	int mmin = 0;
	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		
		ret = f(i);
		if (ret == 1) {
			if (sum == 0){
				mmin = i;
			}
			sum+=i;
		}
			
	}
	if (sum == 0)
		cout << -1 << endl;
	else {
		cout << sum << endl;
		cout << mmin << endl;
	}
	return 0;
}