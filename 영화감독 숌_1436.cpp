#include <iostream>
#include <string>
using namespace std;


int main() {
	int n;
	int find = 0;
	int num = 1;

	cin >> n;

	while (1) {
		string test = to_string(num);

		if (test.find("666")!=string::npos) {
			find++;
		}
		
		if (find == n) {
			break;
		}

		num++;
	}

	cout << num << endl;
}