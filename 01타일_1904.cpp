#include <iostream>

using namespace std;
int number;
int arr[1000001] = { 0 };
#define N 15746
int f(int n) {
	
	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1]%N + arr[i - 2]%N;
	}

	return arr[n]%N;
		
}

int main() {
	
	arr[1] = 1;
	arr[2] = 2;

	cin >> number;
	int ret = f(number);
	cout << ret<< endl;
}