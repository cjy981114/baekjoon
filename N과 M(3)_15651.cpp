#include <iostream>

using namespace std;

int n, m;
int arr[8] = { 0 };
bool check[8] = { false };
void f(int a) {

	if (a == m) {
		for (int i = 1; i <= m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[a + 1] = i;
		f(a + 1);
	}

}

int main() {
	cin >> n >> m;
	f(0);
	return 0;
}