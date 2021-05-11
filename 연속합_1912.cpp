#include <iostream>

using namespace std;

long long int d[100001] = { 0 };

int arr[100001] = { 0 };
int num = 0;

int main() {
	cin >> num;


	for (int i = 1; i <= num; i++) {
		cin >> arr[i];
	}

	d[1] = arr[1];

	for (int i = 2; i <= num; i++) {
		if (d[i - 1] + arr[i] <= arr[i]) {
			d[i] = arr[i];
		}
		else {
			d[i] = d[i - 1] + arr[i];
		}
		
	}


	long long int findMax = d[1];
	for (int i = 2; i <= num; i++) {
		if (findMax <= d[i]) {
			findMax = d[i];
		}
	}

	cout << findMax << endl;
}