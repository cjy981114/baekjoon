#include <iostream>

using namespace std;

int n, m, k;
int a1[100][100] = { 0 };
int a2[100][100] = { 0 };
int ans[100][100] = { 0 };
void f() {
	for (int i = 0; i < n; i++) {
		for (int z = 0; z < k; z++) {
			for (int j = 0; j < m; j++) {
				ans[i][z] += a1[i][j] * a2[j][z];
			}
		}
		
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a1[i][j];
		}
	}
	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> a2[i][j];
		}
	}

	f();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << ans[i][j] << " ";
		}cout << endl;
	}
}