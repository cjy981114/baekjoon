#include <iostream>


using namespace std;
long long n, k;
bool go(long long num) {
	long long cnt = 0;

	//시간 초과
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i * j <= num)
				cnt++;
		}
	}*/
	
	//시간 초과 안 뜨는 방법
	for (int i = 1; i <= n; i++) {
		cnt += min(num / i, n);
	}
	
	if (cnt >= k)
		return true;
	else
		return false;
}

long long f(long long start, long long end) {
	long long mid = (start + end) / 2;
	if (start > end)
		return 1000000001;

	if (go(mid)) {
		return min(mid,f(start, mid-1));
	}
	else {
		return f(mid+1,end);
	}

}

int main() {
	cin >> n >> k;

	long long endnum = n * n;

	long long ret = f(1, endnum);
	cout << ret << endl;
}