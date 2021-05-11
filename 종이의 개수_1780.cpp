#include <iostream>

using namespace std;

int n;
int arr[2187][2197] = { 0 };

int minus_One= 0;
int zero = 0;
int plus_One = 0;

int check(int* test) {
	int go = test[0];
	int cnt = 0;
	int find_minus = 0;
	int find_zero = 0;
	int find_plus = 0;

	
	for (int i = 0; i < 9; i++) {
		if (test[i] == go)
			cnt++;
		if (test[i] == -1)
			find_minus++;
		else if (test[i] == 0)
			find_zero++;
		else if (test[i] == 1)
			find_plus++;
		else
			continue;
	}

	if (cnt == 9)
		return go;
	else {
		minus_One += find_minus;
		zero += find_zero;
		plus_One += find_plus;
		return 10000;
	}
}

int f(int a, int b, int size) {

	if (size == 1) {
		if (arr[a][b] == -1)
			return -1;
		else if (arr[a][b] == 0)
			return 0;
		else if (arr[a][b] == 1)
			return 1;
	}

	int ret[9] = { 0 };
	int z = 0;

	for (int i = 0; i < size; i += (size / 3)) {
		for (int j = 0; j < size; j += (size / 3)) {
			ret[z] = f(a + i, b + j, size / 3);
			z++;
		}
	}
	
	int checkAll = check(ret);
	if (checkAll !=10000) {
		return checkAll;
	}
	else {
		return 10000;
	}

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int ret = f(0, 0, n);
	if (ret != 10000) {
		if (ret == -1)
			minus_One++;
		else if (ret == 0)
			zero++;
		else if (ret == 1)
			plus_One++;
	}

	cout << minus_One << endl;
	cout << zero << endl;
	cout << plus_One << endl;
}
