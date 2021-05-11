#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0;
int d[100] = { 0 };
vector<pair<int, int>> arr;
int f(int n) {
	

	int tMax = 0;
	d[0] = 1;
	int ret = 0;
	for (int i = 1; i < num; i++) {//Àü±ê¼ö ¼ö
		int secondOne = arr[i].second;
		for (int j = i-1; j>=0; j--) {
			if (secondOne > arr[j].second) {
				d[i] = max(d[i],d[j]+1);
			}
			
		}
		if (d[i] == 0) {
			d[i] = 1;
		}

		ret = max(ret, d[i]);
	}

	
	return ret;
}


int main() {
	cin >> num;

	int a, b;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}
	sort(arr.begin(), arr.end());

	int ret = f(0);

	cout << num-ret << endl;
}