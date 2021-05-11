#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num;
vector<pair<int, int>> arr;

int main() {

	cin >> num;
	int a, b;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		arr.push_back(make_pair(b, a));
	}

	sort(arr.begin(), arr.end());

	int maxNum = arr[0].first;
	int cnt = 1;
	for (int i = 1; i < num; i++) {
		if (maxNum <= arr[i].second) {
			cnt++;
			maxNum = arr[i].first;
		}
	}

	cout << cnt << endl;
	
}