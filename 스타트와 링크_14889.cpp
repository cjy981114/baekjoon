#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int s[21][21] = { 0 };
vector<vector<int>> start(2);
//vector<int> link;
int team[2] = { 0 };
int test_s=0;
int test_l=0;
int go = 99999999;
int f(int cnt);

int findMin() {
	int sum_s = 0, sum_l = 0;

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			sum_s += s[start[0][i]][start[0][j]];
			sum_l += s[start[1][i]][start[1][j]];
		}
		
	}
	return abs(sum_s - sum_l);
}
int f(int cnt) {
	if (cnt == n + 1) {
		int ret = findMin();
		return ret;
	}
		

	for (int i = 0; i < 2; i ++ ) {
		if (team[i] != 0) {
			team[i]--;
			start[i].push_back(cnt);
			go  = min(go,f(cnt + 1));
			start[i].pop_back();
			team[i]++;
		}
	}
	return go;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}
	team[0] = n / 2;
	team[1] = n / 2;
	

	int ret = f(1);
	cout << ret << endl;
	return 0;
}