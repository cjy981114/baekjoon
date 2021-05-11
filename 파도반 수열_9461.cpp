#include <iostream>

using namespace std;
long long int arr[101] = { 0,1,1 };

long long int func(int n) {
	if (n <= 2) {
		return arr[n];
	}
	else {
		for (int i = 3; i <= n; i++) {
			arr[i] = arr[i - 2] + arr[i - 3];
		}
	}

	return arr[n];
}

int main() {
	int tc;
	cin >> tc;
	int num;
	
	while (tc > 0) {

		cin >> num;
		
		long long int ret = func(num);
		cout << ret << endl;
		--tc;
	}
}