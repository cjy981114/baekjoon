#include <iostream>
#include <cstring>//memset
#include <cmath>
using namespace std;

int n, m;
int a[31] = { 0 };
int d[31][40001] = { 0 };

void f(int cnt, int weight) {
	if (cnt > n) {
		return;
	}

	int& ret = d[cnt][weight];
	if (ret != -1)
		return;

	d[cnt][weight] = 1;


	f(cnt + 1, weight + a[cnt+1]);

	f(cnt + 1, weight);

	f(cnt + 1, abs(weight - a[cnt+1]));


	return;
}

int main() {
	cin >> n;//Ãß

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	memset(d, -1, sizeof(d));
	

	cin >> m;//±¸½½

	f(0, 0);
	
	int mm[7];
	for (int i = 0; i < m; i++) {
		cin >> mm[i];
	}

	for (int i = 0; i < m; i++) {

		if (d[n][mm[i]] == 1)
			cout << "Y ";
		else
			cout << "N ";

	}

	return 0;
}