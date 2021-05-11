#include <iostream>


using namespace std;

int n;
int main() {
	cin >> n;

	int i = 0;
	int start = 1;
	

	while (start < n) {
		start = start + i * 6;
		i++;
	}

	if (n == 1)
		i = 1;

	cout << i << endl;
}