#include <iostream>
#include <cmath>
using namespace std;

int k;
int a[3000000];
int result = 0;
int treesize = 0;
int f(int num) {
	if (num > treesize) {
		return 0;
	}

	int le = f(num * 2);
	int ri = f(num * 2 + 1);

	result += a[num] + abs(le-ri);
	return a[num] + max(le, ri);

}
int main() {
	cin >> k;
	treesize = 1 << (k + 1);
	
	for (int i = 2; i < treesize; i++) {
		cin >> a[i];
	}

	f(1);
	cout << result << endl;
	return 0;

}