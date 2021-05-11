#include <iostream>

using namespace std;

int c_time[16];
int c_money[16];
int n;
int d[17] = { 0 };

void f() {
	
	for (int i = n; i > 0; i--) {
		if (i + c_time[i] <= (n + 1)) {
			d[i] = max(d[i+1],d[i + c_time[i]] + c_money[i]);
		}
		else {
			d[i] = d[i+1];
		}
	}
}


int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> c_time[i] >> c_money[i];
	}

	f();

	cout << d[1] << endl;
}