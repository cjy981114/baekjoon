#include <iostream>
#include <limits.h>
using namespace std;

int n;
int arr[100001];
int dp[100001] = {0};

int main() {
	int fmax = INT_MIN;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		if (dp[i - 1] > 0) {
			dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		}
		else {
			dp[i] = arr[i];
		}
		fmax = max(fmax, dp[i]);
	}
	cout << fmax << endl;
	
	return 0;
}