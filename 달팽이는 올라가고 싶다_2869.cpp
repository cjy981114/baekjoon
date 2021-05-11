#include <iostream>

using namespace std;


int main() {
	int a = 0;
	int b = 0;
	int v = 0;
	cin >> a >> b >> v;
	
	int last = v - a;
	int day = 1;

	if ((last %(a - b))==0) {
		day = last / (a - b);
		cout << day+1 << endl;
	}
	else {
		day = last / (a - b);

		cout << day + 2 << endl;
	}
	
}