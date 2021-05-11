#include <iostream>
#include <vector>
using namespace std;

long long rest = 1000000007;
long long n;
vector<vector<long long>> set(2, vector<long long> (2));

vector<vector<long long>> multi(vector<vector<long long>> a, vector<vector<long long>>b){
	vector<vector<long long >> c(2, vector<long long>(2));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= rest;
			}
		}
	}

	return c;

}

vector<vector<long long>> f(long long cnt) {
	if (cnt == 1) {
		
		return set;
	}
		

	if (cnt % 2 == 1) {
		vector<vector<long long>> t1 = f(cnt - 1);
		vector<vector<long long >> t2 = multi(set, t1);
		
		return t2;
	}
	else {
		vector<vector<long long>> half = f(cnt / 2);
		vector<vector<long long >> t2 = multi(half, half);
		return t2;
	}
}


int main() {
	cin >> n;
	set[0][0] = set[0][1] = set[1][0] = 1;
	set[1][1] = 0;
	
	vector<vector<long long>> ret = f(n);

	cout << ret[0][1] % rest << endl;

}