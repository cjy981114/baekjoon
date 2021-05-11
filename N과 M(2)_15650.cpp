#include <iostream>

using namespace std;

int n, m;

int arr[9] = { 0 };
bool check[9] = { false };

void f(int a) {


	if (a == m) {
		for (int i = 1; i <= m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= n; i++) {
		if (arr[a]<i && check[i] == false) {
			check[i] = true;
			arr[a+1] = i;
			f(a + 1);
			check[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	f(0);
	return 0;
}