#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr_n(100000, 0);
vector<int> arr_m(100000, 0);
bool f(int num) {
	int mid_n = arr_n[n / 2];

	if (num == mid_n)
		return true;
	else if (num < mid_n) {
		for (int i = 0; i < n/2; i++) {
			if (num == arr_n[i])
				return true;
		}
	}
	else if (num > mid_n) {
		for (int i = n / 2 + 1; i < n; i++) {
			if (num == arr_n[i])
				return true;
		}
	}

	return false;
}

int main() {
	//이건 시간초과가 뜰 때
	ios_base::sync_with_stdio(0);
	
	cin.tie(0);
	//

	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr_n[i] = a;
	}
		

	sort(arr_n.begin(), arr_n.begin()+n);


	cin >> m;
	int b;
	for (int i = 0; i < m; i++) {
		cin >> b;
		arr_m[i] = b;
	}
	

	vector<int> ans;


	for (int i = 0; i < m; i++) {
		int check = f(arr_m[i]);

		if (check)
			ans.push_back(1);
		else
			ans.push_back(0);
	}

	for (int i = 0; i < m; i++) {
		cout << ans[i] << "\n"; //\n도 시간초과가 뜨면
	}

	return 0;
}