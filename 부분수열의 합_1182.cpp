#include <iostream>
#include <vector>
using namespace std;
int n, s;
int arr[21] = { 0 };
int cnt = 0;
vector<int>sub_str;
void check() {
	int sum = 0;
	for (int i = 0; i < sub_str.size(); i++) {
		sum += sub_str[i];
	}

	if (sum == s) {
		cnt++;
	}
	return;

}

void f(int num) {


	for (int i = num + 1; i < n+1; i++) {
		sub_str.push_back(arr[i]);
		check();
		f(i);
		sub_str.pop_back();
	}
}


int main() {
	int cnt_zero = 0;
	cin >> n >> s;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		
	}

	f(0);

	cout << cnt << endl;
}