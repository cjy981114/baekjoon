#include <iostream>

using namespace std;


int n, m;
int arr[9];
bool check[9] = { 0,};

void f(int a) {

	if (a == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		
		if (check[i] == false) {
			check[i] = true;
			arr[a] = i;
			f(a+1);
			check[i] = false;
		}
	}
}

int main() {
	
	cin >> n >> m;
	
	f(0);

	return 0;
}