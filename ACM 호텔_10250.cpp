#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;
	int h, w, n;
	while (tc > 0) {
		cin >> h >> w >> n;

		if (n % h == 0)
			cout << h *100+ (n / h) << endl;
		else
			cout << (n % h)*100+ (n / h) + 1 << endl;
		tc--;
	}
}