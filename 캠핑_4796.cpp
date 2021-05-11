#include <iostream>

using namespace std;

int main() {
	int l, p, v;
	int i = 1;
	while (1) {
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)
			break;
		int a1 = (v / p)* l;
		int b1 = 0;
		if (v % p < l) {
			b1 = v % p;
		}
		else
			b1 = l;
		
		cout << "Case " << i << ": " << a1 + b1 << endl;
		i++;
	}
}