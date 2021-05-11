#include <iostream>

using namespace std;
bool a[246913];
int n;
void f2(int num) {
	for (int i= num * 2; i <= n*2; i += num) {
		a[i] = true;
	}
}
void f() {
	
	for (int i = 2; i <= n*2; i++) {
		if (a[i] == false) {
			f2(i);
		
		}
	}
}
int main() {
	
	a[1] = true;
	while (1) {
		int count = 0;
		cin >> n;
		if (n == 0)
			break;
		f();
		for (int i = n+1; i <= n * 2; i++) {
			if (a[i] == false) {
				count++;
			}
				
		}
		cout << count << endl;
	}
	return 0;
}