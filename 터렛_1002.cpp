#include <iostream>

using namespace std;

int main() {
	int tc;
	int x1, y1, r1, x2, y2, r2;
	cin >> tc;

	while (tc){
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int d = (x1 - x2) * (x1 - x2) + (y1-y2)*(y1-y2);

		int dmin = (r1 - r2) * (r1 - r2);
		int dmax = (r1 + r2) * (r1 + r2);

		if (d == 0 && dmin == 0) {
			cout << -1 << endl;
		}
		else if (dmin < d && d < dmax)
			cout << 2 << endl;
		else if (d == dmax || d==dmin)
			cout << 1 << endl;
		else {
			cout << 0 << endl;
		}

		--tc;
	}

}