#include <iostream>

using namespace std;
int a[51][51];
int f(int r, int c, int d) {
	
	int curr = a[r][c];
	
	int up = a[r - 1][c];
	int down = a[r + 1][c];
	int left = a[r][c-1];
	int right = a[r][c+1];
	if (curr == 1)
		return 0;

	a[r][c] = 2;
	
	if (d == 0) {
	
		if ((up == 1 ||up==2) &&( down == 1||down==2) && (left == 1 ||left==2)&& (right == 1||right==2)) {
			if (a[r + 1][c] == 1) {
				return 1;
			}
			else {
				return f(r + 1, c, d);
			}
		}
			

		if (left == 0) {
		
			return f(r, c - 1, 3) + 1;
		}
		else if (down == 0) {
			
			return f(r + 1, c, 2) + 1;
		}
		else if (right == 0) {
			
			return f(r, c + 1, 1) + 1;
		}
		else if(up==0){
			
			return f(r - 1, c, 0) + 1;
		}

	}
	else if (d == 1) {
		if ((up == 1 || up == 2) && (down == 1 || down == 2) && (left == 1 || left == 2) && (right == 1 || right == 2)) {
			if (a[r][c - 1] == 1) {
				return 1;
			}
			else {
				return f(r, c - 1, d);
			}
		}
		

		if (up == 0) {
			
			return f(r-1, c , 0) + 1;
		}
		else if (left == 0) {
			
			return f(r, c-1, 3) + 1;
		}
		else if (down == 0) {
			
			return f(r+1, c , 2) + 1;
		}
		else if(right==0){
			
			return f(r, c+1, 1) + 1;
		}
	}
	else if (d == 2) {
		if ((up == 1 || up == 2) && (down == 1 || down == 2) && (left == 1 || left == 2) && (right == 1 || right == 2)) {
			if (a[r - 1][c] == 1) {
				return 1;
			}
			else {
				return f(r - 1, c, d);
			}
		}

		if (right == 0) {
			
			return f(r , c+1, 1) + 1;
		}
		else if (up == 0) {
			
			return f(r-1, c , 0) + 1;
		}
		else if (left == 0) {
			
			return f(r, c-1, 3) + 1;
		}
		else if(down==0){
			
			return f(r+1, c, 2) + 1;
		}
	}
	else {//d=3
		if ((up == 1 || up == 2) && (down == 1 || down == 2) && (left == 1 || left == 2) && (right == 1 || right == 2)) {
			if (a[r][c + 1] == 1) {
				return 1;
			}
			else {
				return f(r, c + 1, d);
			}
		}

		if (down == 0) {
			
			return f(r+1, c, 2) + 1;
		}
		else if (right == 0) {
			
			return f(r, c + 1, 1) + 1;
		}
		else if (up == 0) {
			
			return f(r - 1, c, 0) + 1;
		}
		else if(left==0){
			
			return f(r, c-1 , 3) + 1;
		}
	}
	
}


int main() {
	int n, m;
	int r, c;
	int d;
	
	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ret = f(r, c, d);
	cout << ret << endl;
}