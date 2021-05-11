#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> arr;
int n;
int test = 1000000000;
int f(int cnt) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int ff = arr[j].first - arr[i].first;
			int ss = arr[j].second - arr[i].second;
			test = min(test, ff * ff + ss * ss);
		}
	}
	return test;
}


int main() {
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}

	sort(arr.begin(), arr.end());

	int ret = f(0);
	cout << ret << endl;
	/*for (int i = 0; i < n; i++) {
		cout << arr[i].first << " " << arr[i].second << endl;
	}*/
}