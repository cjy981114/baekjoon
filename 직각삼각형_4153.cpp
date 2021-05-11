#include <iostream>

using namespace std;

int main() {
	int a, b, c;

	while (1) {
		cin >> a >> b >> c;
		
		if (a == 0 && b == 0 && c == 0)
			return 0;

		
		int pa = a * a;
		int pb = b * b;
		int pc = c * c;

		if (((pa + pb) == pc) || ((pb + pc) == pa) || ((pa + pc) == pb)) {
			cout << "right" << endl;
		}
		else
			cout << "wrong" << endl;
			
	}
	return 0;
}