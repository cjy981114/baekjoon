#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> a;

	int t = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a.push(t);
	}
	
	int sum = 0;
	while (a.size() != 1) {
		int n1 = a.top();
		a.pop();
		int n2 = a.top();
		a.pop();

		sum+= n1 + n2;

		a.push(n1 + n2);
	}

	cout << sum << endl;
	
	return 0;
}