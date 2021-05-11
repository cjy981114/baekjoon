#include <iostream>

using namespace std;

int w[10001] = { 0 };
int num = 0;
int s[10001] = { 0 };
int f() {
	
	s[1] = w[1];
	s[2] = w[1] + w[2];


	for (int i = 3; i <= num; i++) {
		s[i] =  max(s[i - 2]+w[i], s[i-3]+w[i - 1]+w[i]);
		s[i] = max(s[i], s[i - 1]);	//¿ÖÁö..?
	}
	return s[num];


	/*int maxNum = 0;
	for (int i = 1; i <= num; i++) {
		if (maxNum <= s[i]) {
			maxNum = s[i];
		}
	}
	return maxNum;*/
}

int main() {
	cin >> num;

	for (int i = 1; i <= num; i++) {
		cin >> w[i];
	}

	int ret = f();
	cout << ret << endl;
}