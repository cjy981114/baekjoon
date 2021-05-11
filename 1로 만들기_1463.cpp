#include <iostream>

using namespace std;

int num = 0;
int n[1000001] = { 0 };

int f(int num) {
	if (num == 2 || num == 3) {
		return n[num];
	}
	
	int ret = 0;

	for (int i = 4; i <= num; i++) {

		int test1 = 99999;
		int test2 = 99999;
		if ((i % 3) == 0) {
			test1 = n[i/3] + 1;
		}
		if ((i % 2) == 0) {
			test2 = n[i/2] + 1;
		}

		ret = min(test1,test2);
		n[i] = min(ret, n[i - 1] + 1);
	}
		

	return n[num];
}



int main() {
	cin >> num;

	n[2] = 1;
	n[3] = 1;

	int ret = f(num);
	cout << ret << endl;
	
}