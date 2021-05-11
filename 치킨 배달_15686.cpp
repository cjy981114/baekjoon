#include<iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
int n, m;
int arr[52][52];
bool visit[52][52];

vector<int> ch_x;
vector<int> ch_y;
int ans = INT_MAX;
vector<pair<int, int>> house;
void calc_distance() {
	
	int hsize = house.size();
	
	int ret = 0;
	for (int i = 0; i < hsize; i++) {
		int mmin = INT_MAX;
		for (int j = 0; j < m; j++) {
			mmin = min(mmin, abs(house[i].first - ch_x[j]) + abs(house[i].second - ch_y[j]));
		}
		ret += mmin;
	}

	ans = min(ans, ret);
	return;
}


void f(int i, int j, int cnt) {
	if (cnt == m) {
		calc_distance();
		return;
	}

	if (i > n || j > n) {
		return;
	}

	int mmin = INT_MAX;
	

	int a = i;
	int b = j+1;
	if (b > n) {
		a++;
		b = 1;
	}
	while (a <= n && b <= n) {
		if (arr[a][b] == 2 && visit[a][b] == false) {
			ch_x.push_back(a);
			ch_y.push_back(b);
			visit[a][b] = true;
			f(a, b, cnt + 1);
			ch_x.pop_back();
			ch_y.pop_back();
			visit[a][b] = false;
		}
		b++;
		if (b > n) {
			a++;
			b = 1;
		}
	}

	return;

}


int main(){
	
	scanf_s("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf_s("%d",&arr[i][j]);
			if (arr[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
		}
	}

	f(1, 0, 0);
	printf("%d\n", ans);
}