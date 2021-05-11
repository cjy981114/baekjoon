#include <iostream>

using namespace std;

long long int arr[101][101][101] = { 0 };

long long int func(int a, int b, int c) {

	if (a <= 0 || b <= 0 || c <= 0) {
		arr[a + 50][b + 50][c + 50]=1;
		return 1;
	}

	if (a>20 || b>20 || c>20) {
		if (arr[a + 50][b + 50][c + 50] != 0) {
			return arr[a + 50][b + 50][c + 50];
		}
		else {
			arr[a+50][b+50][c+50] = func(20, 20, 20);
			return arr[a + 50][b + 50][c + 50];
		}
	}


	if (a < b && b < c) {
		if (arr[a + 50][b + 50][c + 50] != 0) {
			return arr[a + 50][b + 50][c + 50];
		}
		else {
			arr[a + 50][b + 50][c + 50] = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);
			return arr[a + 50][b + 50][c + 50];
		}
		
	}
	else {
		if (arr[a + 50][b + 50][c + 50] != 0) {
			return arr[a + 50][b + 50][c + 50];
		}
		else {
			arr[a + 50][b + 50][c + 50] = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
			return arr[a + 50][b + 50][c + 50];
		}
		
	}

}


int main() {
	int a, b, c;
	arr[50][50][50] = 1;

	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;

		long long int ret = func(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << ret << endl;
	}
	

	return 0;
}