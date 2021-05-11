#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<long long> arr;
long long mmin;
bool check(int num) {

	int cnt = 1;
	int goStart = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] - goStart >= num) {
			cnt++;
			goStart = arr[i];
		}
	}

	if (cnt >= c)
		return true;
	else
		return false;
}

long long f(long long start, long long end) {
	
	long long mid = (start + end) / 2;
	//cout << "mid:" <<mid<< endl;
	if (start > end)
		return 0;

	if (check(mid)) {
		return max(mid, f(mid + 1, end));
	}
	else {
		return f(start, mid - 1);
	}

}

int main() {
	cin >> n >> c;

	long long a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());
	
	long long ret = f(1, arr[n - 1]);
	printf("%lld\n", ret);
	
}
