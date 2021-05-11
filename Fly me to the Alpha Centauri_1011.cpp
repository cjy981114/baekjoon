#include <iostream>

using namespace std;
long long a, b;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	
	cin >> tc;

	while (tc > 0) {

		cin >> a >> b;

		long long go = b - a;
		long long  i = 1;
		while (1) {

			if (i * i >= go) {
				if ((i * i - go) >= i) {
					cout << i * 2 - 2 << endl;
					break;
				}
				else {
					cout << i * 2 - 1 << endl;
					break;
				}
			}

			i++;
		}
		--tc;
	}
}