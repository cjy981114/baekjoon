#include <iostream>

using namespace std;

int num;
int money = 0;
int arr[10] = { 0 };
int main() {

	cin >> num>>money;

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = num - 1; i >= 0; i--) {
		if (money>0&&arr[i] <= money) {
			sum+=money / arr[i];
			money = money % arr[i];
		}
	}
	
	cout << sum << endl;
}