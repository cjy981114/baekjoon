#include <iostream>

using namespace std;
long long a, b;
int ret = -1;

void f(long long num, int cnt) {

	if (num == b) {
		ret = cnt;
	}
	if (num > b) {
		return;
	}


	f(num * 2,cnt+1);

	f(num * 10 + 1, cnt+1);

	return;
}


int main() {
	cin >> a >> b;

	f(a,1);

	cout << ret << endl;

	return 0;
	
}