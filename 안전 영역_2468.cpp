#include <iostream>
#include<limits.h>
using namespace std;

int n;
int a[102][102] = {0};
int nmax = 0;
int area_max = 0;
int area_num = 0;
bool check[102][102];
void find(int x, int y, int height, int cnt) {

	if (check[x][y]==true) {	//작거나 이미 체크한 영역이면 그냥 리턴.
		return;
	}


	for (int i = x;i <= n; i++) {
		for (int j = y; j <= n; j++) {
			
			if (a[i][j] > height && check[i][j] == false) {
				cout << "(" << i << "," << j << ")  a[i][j]:"<<a[i][j]<<"  height: " <<height<< endl;
				check[i][j] = true;
				if (a[i - 1][j] > height && check[i - 1][j] == false) {//상
					find(i - 1, j, height, cnt + 1);
				}
				if (a[i][j + 1] > height && check[i][j + 1] == false) {//우
					find(i, j + 1, height, cnt + 1);
				}
				if (a[i + 1][j] > height && check[i + 1][j] == false) {//하
					find(i + 1, j, height, cnt + 1);
				}
				if (a[i][j - 1] > height && check[i][j - 1] == false) {//좌
					find(i, j - 1, height, cnt + 1);
				}

				if (cnt == 1) {
					//cout << endl;
					cout << "영역 표시 (" << i << "," << j << ")" << endl;
					area_num++;
				}

				if (cnt!=1 &&  (a[i - 1][j] <= height || check[i - 1][j] == true) && (a[i][j + 1] <= height || check[i][j + 1] == true) && (a[i + 1][j] <= height || check[i + 1][j] == true)  &&  (a[i][j-1]<=height || check[i][j-1]==true) ) {
					//area_num++;
					return;
				}

			}
			/*else {
				return;
			}*/
			
		}
	}
}


void init() {

	area_num = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			check[i][j] = false;
		}
	}
}
void f() {



	for (int i = nmax-1 ; i >= 0; i--) {
		
		init();
		find(1, 1, i, 1);
		area_max = max(area_max, area_num);
	}


}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			nmax = max(nmax, a[i][j]);
		}
	}
	
	f();

	cout << area_max << endl;

}