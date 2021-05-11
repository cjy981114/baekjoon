#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int big = 10000000;
int test[20000001] = { 0 };
vector<int> ans(500000, 0);

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		test[big + a]++;
	}

	cin >> m;
	int b;
	for (int i = 0; i < m; i++) {
		cin >> b;
		if (test[big + b] != 0) {
			ans[i] = test[big + b];
		}
	}


	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}