#include <iostream>

using namespace std;

int tri[500][500] = {0};
int line = 0;
int dp[500][500] = {};
int f(int i, int j) {

	int ret = dp[i][j];

	if (ret != -1) {
		return ret;
	}

	if (i == (line - 1)) {
		dp[i][j] = tri[i][j];
		return dp[i][j];
	}

	int m1 = f(i + 1, j);
	int m2 = f(i + 1, j + 1);

	int mm = max(m1, m2);

	int test = mm + tri[i][j];
	

	dp[i][j] = test;

	return test;
}
void init() {
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++) {
			dp[i][j] = -1;
		}
	}
}

int main() {
	cin >> line;
	init();
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> tri[i][j];
		}
	}
	int ret = f(0,0);
	cout << ret << endl;
}