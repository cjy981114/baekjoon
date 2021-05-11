#include <iostream>

using namespace std;
int h[1001][3] = { 0 };

int dp[1001][3] = { 0 };

int house;
int f() {
	
	dp[1][0] = h[1][0];
	dp[1][1] = h[1][1];
	dp[1][2] = h[1][2];

	for (int i = 2; i <= house; i++) {

		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + h[i][0];
		
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + h[i][1];

		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + h[i][2];
	}

	int minNum = min(dp[house][0], dp[house][1]);
	minNum = min(minNum, dp[house][2]);

	return minNum;
}




int main() {
	cin >> house;

	for (int i = 1; i <= house; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> h[i][j];
		}
	}

	int ret = f();
	cout << ret << endl;
}