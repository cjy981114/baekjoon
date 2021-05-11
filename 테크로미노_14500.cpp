#include <iostream>

using namespace std;

int n, m;
int a[502][502];
bool visit[501][501] = {false};
int f(int r, int c, int cnt) {

	if (r > n || c > m) {
		return 0;
	}
	if (cnt > 4) {
		return 0;
	}

	visit[r][c] = true;

	int up=0;
	int right=0;
	int down=0;

	int spc_current = a[r][c];
	int spc_down=a[r+1][c];
	int spc_right=a[r][c+1];
	int spc_up = a[r-1][c];
	int spc_left = a[r][c-1];
	int findmax = 0;
	if (cnt == 1) {
		int block_down = spc_current + spc_left + spc_right + spc_down;
		int block_up = spc_current + spc_left + spc_right + spc_up;
		int block_right = spc_up + spc_current + spc_right + spc_down;
		int block_left = spc_current + spc_left + spc_up + spc_down;
		int blocks[4] = { block_down, block_up, block_right, block_left };
		findmax = blocks[0];
		for (int i = 1; i < 4; i++) {
			if (findmax < blocks[i]) {
				findmax = blocks[i];
			}
		}
	}
	
	if(c<m&&visit[r][c+1]==false){
		right = f(r, c + 1, cnt + 1);
	}
	if(r<n&&visit[r+1][c]==false){
		down = f(r + 1, c, cnt + 1);
	}
	
	if (1 < r && visit[r - 1][c]==false) {
		up = f(r - 1, c, cnt + 1);
	}

	visit[r][c] = false;

	int findmax2 = max(up, max(right, down)) + a[r][c];
	int mmax = max(findmax, findmax2);

	return mmax;

}

int main() {
	int mmax = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			visit[i][j] = false;
		}
	}

	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mmax= max(mmax,f(i, j, 1));
			
		}
	}

	cout << mmax << endl;
}