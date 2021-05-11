#include <iostream>
using namespace std;
int f(int num);
int n[1000000] = {0};
int main() {
	int num;
	cin >> num;
	int ret = f(num);

	cout << ret << endl;
}

int f(int num) {
	
	n[1] = 0;

	for (int i = 2; i <= num; i++) {
		n[i] = n[i - 1] + 1;

		if (i % 5 == 0) {
			n[i] = min(n[i],n[i / 5] + 1);
		}
		if (i % 3 == 0) {
			n[i] = min(n[i],n[i / 3] + 1);
		}
		if (i % 2 == 0) {
			n[i] = min(n[i],n[i / 2] + 1);
		}
	}
	

	return n[num];

}