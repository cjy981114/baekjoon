#include <iostream>
#include <vector>

using namespace std;

long long n, b;
vector<vector<long long>> arr(5,vector<long long>(5)) ;
const int rest = 1000;

vector<vector<long long>> multiple(vector<vector<long long>> b1, vector<vector<long long>> b2){
	vector<vector<long long>> test(n, vector<long long>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				test[i][j] +=(b1[i][k]%rest) * (b2[k][j]%rest);
				test[i][j] %= rest;
			}
		}
	}
	
	return test;
}


vector<vector<long long>> f(long long cnt) {


	if (cnt == 1) {
		return arr;
	}

	if (cnt % 2 == 1) {
		vector<vector<long long>> gett = f(cnt - 1);
		return multiple(arr, gett);
	}
	else {
		vector<vector<long long>> gett= f(cnt / 2);
		return multiple(gett, gett);
	}
}

int main() {
	cin >> n >> b;
	int tt;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tt;
			arr[i][j] = tt;
		}
	}
	
	vector<vector<long long>> ret = f(b);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ret[i][j]%rest<<" ";
		}cout << endl;
	}


	return 0;
}

