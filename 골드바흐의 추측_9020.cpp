#include<iostream>
#include <vector>
using namespace std;
int n;
int f1, f2;
bool a[10001];
void making(int num) {
	for (int i = num * 2; i <= n; i+=num) {
		a[i] = true;
	}
}
void f() {
	vector<int> find;
	for (int i = 2; i <= n; i++) {
		if (a[i] == false) {
			making(i);
			find.push_back(i);
		}
	}
	
	for (int i = 0; i < find.size(); i++) {
		for (int j = i; j < find.size(); j++) {
			if (find[i] + find[j] == n) {
				f1 = find[i];
				f2 = find[j];
			}
		}
	}
}
int main() {
	int tc;
	cin >> tc;

	while (tc) {
		cin >> n;
		f();
		cout << f1 << " " << f2 << endl;
		--tc;
	}
}