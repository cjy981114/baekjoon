#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
bool compare(int i, int j) {
	return j<i;
}
int main() {
	int tc;
	cin >> tc;

	int n, m;
	
	
	while (tc) {
		queue<pair<int, int>> narr;
		vector<int> nlist;
	
		int num;
		
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> num;
			if (i == m) {
				narr.push(make_pair(num, 1));
			}
			else {
				narr.push(make_pair(num, 0));
			}
				
			
			nlist.push_back(num);
			
		}
		
		sort(nlist.begin(), nlist.end(), compare);

		int cnt = 0;
		
		int a= 0;
		
		while(1){
			if (narr.front().first < nlist[a]) {
				int ffront = narr.front().first;
				int ffront_ind = narr.front().second;
				narr.pop();
				narr.push(make_pair(ffront, ffront_ind));
				
			}
			else if (narr.front().first == nlist[a]) {
				cnt++;
				
				if (narr.front().second == 1)
					break;

				narr.pop();
				a++;
			}
			
		}
		
		
		cout << cnt << endl;

		--tc;
	}
}
