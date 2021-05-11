#include <iostream>

using namespace std;

int n;
long long w;
long long c[16];
int main() {
	cin >> n>>w;

	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}

	//사고 -> 팔고

	bool buy = false;
	long long coin = 0;
	int mmin = c[1]+1;
	int mmax = 0;

	for (int i = 1; i <= n; i++) {
		if (buy == false) {//사야 한다..제일 쌀 때
			if (mmin > c[i]) {
				mmin = c[i];
			}
			else {
				mmax = c[i];
				coin = w / mmin;
				w = w % mmin;
				buy = true;
			}
		}
		if (buy == true) {//팔아야 한다..제일 비쌀 때
			if (mmax < c[i]) {
				mmax = c[i];
			}
			else {
				w += (coin * mmax);
				mmin = c[i];
				buy = false;
			}
		}
	}

	cout << w << endl;
}