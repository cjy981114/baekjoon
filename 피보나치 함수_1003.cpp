#include <iostream>

using namespace std;

int arr[2][41] = { 0 };
int number;
void fibo(int n) {
	if (n == 0 || n == 1)
		return;

	if (arr[0][n - 1] != 0||arr[1][n-1]!=0) {

		arr[0][n] = arr[0][n - 2] + arr[0][n - 1];
		arr[1][n] = arr[1][n - 2] + arr[1][n - 1];

	}
	else {
			fibo(n - 1);
			fibo(n - 2);
			arr[0][n] = arr[0][n - 2] + arr[0][n - 1];
			arr[1][n] = arr[1][n - 2] + arr[1][n - 1];
	}	
}
int main() {
	int tc;
	cin >> tc;

	arr[0][0] = 1;
	arr[1][0] = 0;
	arr[0][1] = 0;
	arr[1][1] = 1;

	while (tc > 0) {
		cin >> number;


		if (number == 0 || number == 1) {
			cout << arr[0][number] << " " << arr[1][number] << endl;
		}
		else if(arr[0][number]!=0){
			cout << arr[0][number] << " " << arr[1][number] << endl;
		}
		else {
			fibo(number);
			cout << arr[0][number] << " " << arr[1][number] << endl;
		}
			

		--tc;

	}
}