#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long g;
	cin >> n;
	vector<long long> min;
	vector<long long> plus;
	bool zero = false;
	for (int i = 0; i < n; i++) {
		cin >> g;
		if (g > 0)
			plus.push_back(g);
		else if (g < 0)
			min.push_back(g);
		else
			zero = true;

	}
	long long msize = min.size();
	long long psize = plus.size();
	long long sum = 0;
	if (msize > 0) {
		sort(min.begin(), min.end());

		for (int i = 0; i < msize-1; i += 2) {
			sum += min[i] * min[i + 1];
		}

		if (msize % 2 != 0) {
			if (zero == true)
				sum += 0;
			else
				sum += min[msize - 1];
		}
	}
	if (psize > 0) {
		sort(plus.begin(), plus.end());

		for (int i = psize - 1; i > 0; i -= 2) {
			if (plus[i] == 1 || plus[i - 1] == 1)
				sum += plus[i] + plus[i - 1];
			else
				sum += plus[i] * plus[i - 1];
		}

		if (psize % 2 != 0) {
			sum += plus[0];
		}
	}
	cout << sum << endl;
	

	return 0;
	
}


