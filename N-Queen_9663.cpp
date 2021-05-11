#include <iostream>
#include <math.h>

using namespace std;


int n;
int cnt = 0;
int chess[15] = { 0 };

bool check(int line) {

	for (int i = 0; i < line; i++) {
		if (chess[i] == chess[line] || abs(chess[i] - chess[line]) == line - i) {
			return false;
		}
	}

	return true;


}

void f(int a) {
	if (a == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		chess[a] = i;

		if (check(a)==true) {
			f(a + 1);
		}
	}

}
int main() {
	cin >> n;
	f(0);
	cout << cnt << endl;
	return 0;
}