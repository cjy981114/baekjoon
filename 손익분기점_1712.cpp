#include <iostream>

using namespace std;

long long a, b, c;

int main() {
	scanf_s("%lld %lld %lld", &a, &b, &c);

	long long ret = 0;

	if (b >= c) {
		ret = -1;
	}
	else {
		ret = a / (c - b) + 1;
	}

	printf("%lld\n", ret);

	return 0;
	
}