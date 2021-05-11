#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long int a, b, c;
long long int f(long long int num) {
	if (num == 1) {
		return a;
	}
	
	if (num % 2) {
		long long int even = f(num - 1) * a;
		even = even % c;
		return even;
	}
	else {
		long long int half = f(num / 2);
		half = half % c;
		return (half * half) % c;
	}
	
}


int main() {
	scanf_s("%lld %lld %lld", &a, &b, &c);
	
	long long int ret = f(b);
	printf("%lld", ret % c);
}