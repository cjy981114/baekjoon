#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<long long> arr(10000, 0);

bool count(long long num) {
	long long cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += arr[i] / num;
	}
	if (cnt >= n)
		return true;
	else
		return false;
}
long long  f(long long start, long long end) {
	//cout << "num:" << num << endl;

	long long mid = (start + end) / 2;
	if (start>end)
		return 0;

	if(count(mid)){

		return max(mid,f(mid + 1, end));
	}
	else
		return f(start, mid - 1);
	
}


int main() {
	cin >> k >> n;

	long long a = 0;
	for (int i = 0; i < k; i++) {
		cin >> a;
		arr[i] = a;
		
	}
	sort(arr.begin(), arr.begin()+k);
	long long ret = f(1,arr[k-1]);
	cout << ret << endl;
}