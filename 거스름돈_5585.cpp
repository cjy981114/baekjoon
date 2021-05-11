#include <iostream>

using namespace std;


int main() {
	int money;
	int ch[6] = { 500,100,50,10,5,1 };
	int count = 0;

	cin >> money;
	int change = 1000 - money;

	for (int i = 0; i < 6; i++) {
		if (change >= ch[i]) {
			count += change / ch[i];
			change = change % ch[i];
		}
	}

	cout << count << endl;
}