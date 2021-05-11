#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> gget;
int main() {
	cin >> n;

	if (n == 1)
		return 0;

	while (n > 1) {
		for (int i = 2; i <= n; i++) {
			if (n % i == 0) {
				n = n / i;
				gget.push_back(i);
				break;
			}
		}
	}

	for (int i = 0; i < gget.size(); i++) {
		cout << gget[i] << endl;
	}
}