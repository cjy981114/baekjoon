#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int k;
int arr[14];
vector<int> unit;
int limit_num = 0;
void f(int cnt) {

	if (unit.size() == 6) {
		for (int i = 0; i < 6; i++) {
			cout << unit[i] << " ";
		}cout << endl;
		return;
	}

	for (int i = cnt + 1; i <= k; i++) {
		if (unit.empty()) {
			unit.push_back(arr[i]);
			f(cnt + 1);
			unit.pop_back();
		}
		if (!unit.empty() && unit.back() < arr[i]) {
			unit.push_back(arr[i]);
			f(cnt + 1);
			unit.pop_back();
		}
		
	}
	return;
}


int main() {
	while (1) {
		cin >> k;
		if (k == 0)
			break;
		memset(arr, 0, 14);

		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
		}
		limit_num = k - 6 + 1;
		f(0);
		cout << endl;

	}

	return 0;
}