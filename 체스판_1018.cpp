#include <iostream>

using namespace std;


char chess[50][50] = {0};

int n, m;
int withWhite(int i, int j) {
	int count = 0;
	char startChar = 'W';
	for (int a = i; a < i + 8; a++) {
		for (int b = j; b < j + 8; b++) {
			
			if (startChar != chess[a][b]) {
				count++;
			}

			if (b != j + 7) {
				if (startChar == 'W')
					startChar = 'B';
				else
					startChar = 'W';
			}

		}
	}
	
	return count;
}

int withBlack(int i, int j) {
	int count = 0;
	char startChar = 'B';
	for (int a = i; a < i + 8; a++) {
		for (int b = j; b < j + 8; b++) {
			

			if (startChar != chess[a][b]) {
				count++;
			}

			if (b != j + 7) {
				if (startChar == 'W')
					startChar = 'B';
				else
					startChar = 'W';
			}

		}
	}

	return count;
	
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chess[i][j];
		}
	}

	int countMin = 99999;
	



	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int cnt = min(withWhite(i, j), withBlack(i, j));
			countMin = min(countMin, cnt);
		}
	}

	cout << countMin << endl;
	return 0;
}