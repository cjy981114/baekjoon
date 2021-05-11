#include <iostream>

using namespace std;

long long n, k;
long long rest = 1000000007;
//long long int fact[4000001];
long long a = 1;
long long b = 1;
long long f(long long cnt) {
	if (cnt == 1)
		return b;

	if (cnt % 2 == 1) {
		 return (b*f(cnt - 1)) % rest;
	}
	else {
		long long half = f(cnt / 2)%rest;
		return (half * half) % rest;
	}
}


int main() {
	scanf_s("%lld %lld", &n, &k);
	if (n == k || k == 0) {
		cout << 1 << endl;
		return 0;
	}
	
	for (int i = n; i >= n - k + 1; i--) {
		a = (a * i) % rest;
	}
	
	for (int i = 1; i <= k; i++) {
		b = (b * i) % rest;
	}

	b = f(rest - 2);

	cout << (a * b) % rest << endl;
}