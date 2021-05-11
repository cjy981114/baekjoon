#include <iostream>

using namespace std;

bool a[1001];
int n, k;

int f() {
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		
		for (int j = i; j <= n; j += i) {
			if (a[j] == false) {
				cnt++;
				a[j] = true;
			}

			if (cnt == k) {
				return j;
			}
		}

	}

}

int main() {
	
	cin >> n >> k;

	int ret = f();
	cout << ret << endl;
}