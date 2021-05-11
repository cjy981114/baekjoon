#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;





int main() {
	int tc;
	cin >> tc;
	
	int a, b;
	while (tc > 0) {
		vector <pair<int, int>> worker;
		int pnum;
		cin >> pnum;
		for (int i = 0; i < pnum; i++) {
			cin >> a >> b;
			worker.push_back(make_pair(a, b));
		}

		sort(worker.begin(), worker.end());

		int test = worker[0].second;
		int count = 1;
	
		for (int i = 1; i < pnum; i++) {
			if (test > worker[i].second) {
				count++;
				test = worker[i].second;
			}
		}
		cout << count << endl;
		--tc;
	}
}