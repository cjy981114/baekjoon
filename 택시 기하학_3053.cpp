#include <iostream>
using namespace std;

int main() {
	double r;
	cin >> r;

	double u;
	double t;

	u = r * r * 3.141592653589;
	t = 2.0 * r * r;

	printf("%.6lf\n", u);
	printf("%.6lf\n", t);
}