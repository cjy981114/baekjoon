#include <iostream>
#include <vector>
using namespace std;

int s[9][9] = { 0 };
vector<pair<int, int>> zero;

bool goCheck(int a, int b) {

	int test = s[a][b];
	for (int i = 0; i < 9; i++) {
		if (i != a && s[i][b] == test)
			return false;

		if (i != b && s[a][i] == test)
			return false;
			
	}
	
	int A = (a / 3) * 3;
	int B=(b / 3) * 3;
	for (int i = A; i < A + 3; i++) {
		for (int j = B; j < B + 3; j++) {
			if (i != a && j != b && s[i][j] == test)
				return false;
		}
	}
	
	return true;
}

int f(int n) {
	
	if (n == zero.size()) {
		return 1;
	}

	int a = zero[n].first;
	int b = zero[n].second;

	for (int i = 1; i <= 9; i++) {
		s[a][b] = i;

		if (goCheck(a, b)==true) {
			int ret = f(n + 1);

			if (ret == 1) {
				return 1;
			}
		}
	}
	s[a][b] = 0;
	return 0;
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> s[i][j];
			if (s[i][j] == 0) {
				zero.push_back(make_pair(i, j));
			}
		}
	}
	
	int ret =f(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << s[i][j] << " ";
		}cout << endl;
	}
}