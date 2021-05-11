#include <iostream>

using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int x1 = min(w - x,x);
	int y1 = min(h - y, y);
	int ret = min(x1, y1);

	cout << ret << endl;
}