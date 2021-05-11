#include<iostream>

using namespace std;

int n, m;

int num[101] = { 0 };
int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	int findMax = 0;
	for (int i = 1; i <= n; i++) {
		int a = num[i];
		for (int j = i + 1; j <= n; j++) {
			int b = num[j];
			for (int k = j + 1; k <= n; k++) {
				int c = num[k];

				if ((a + b + c) <= m) {
					findMax = max(findMax, a + b + c);
				}
			}
		}
	}

	cout << findMax << endl;
}