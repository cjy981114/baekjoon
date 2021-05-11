#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string a, b;
	string ans;

	cin >> a >> b;

	int alen = a.length();
	int blen = b.length();
	int maxlen = max(alen, blen);
	
	int minlen = abs(alen - blen);

	string keep;
	for (int i = 0; i < minlen; i++) {
		keep += "0";
	}

	if (alen < blen) {
		a = keep + a;
	}
	else if(alen>blen){
		b = keep + b;
	}
	
	int gonext = 0;

	
	for (int i = maxlen - 1; i >= 0; i--) {
		int n1 = a[i] - '0';
		int n2 = b[i] - '0';
		int plus = gonext + n1 + n2;
		if (plus / 10) {
			gonext = plus / 10;
			plus = plus % 10;
		}
		else {
			gonext = 0;
		}
		char test = (char)plus + '0';
		ans = test + ans;
	}

	if (gonext != 0) {
		char test2 = (char)gonext + '0';
		ans = test2 + ans;
	}
	
	cout << ans << endl;

}
