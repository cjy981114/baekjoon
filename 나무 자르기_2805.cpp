#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<long long> arr;
bool check(int num) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		long long minus = arr[i] - num;
		if (minus > 0)
			sum += minus;
	}

	if (sum >= m)
		return true;
	else
		return false;
}


long long f(long long start, long long end) {
	long long  mid = (start + end) / 2;
	long long sum = 0;

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
	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cin >> n >> m;
	
	long long a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	long long ret = f(1, arr[n-1]);
	printf("%lld\n", ret);
}