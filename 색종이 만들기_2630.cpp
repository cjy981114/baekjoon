#include <iostream>


using namespace std;

int n;
int paper[128][128];
int white=0;
int blue=0;

int f(int a, int b,int size) {

	if (size == 1) {
		if (paper[a][b] == 1) {
			return 10;
		}
		else if (paper[a][b] == 0) {
			return 20;
		}

	}

	int arr[4] = { 0 };
	arr[0] = f(a, b, size / 2);//left_up
	arr[1] = f(a + (size / 2), b, size / 2);//left_down
	arr[2] = f(a, b + (size / 2), size / 2);//right_up
	arr[3] = f(a + (size / 2), b + (size / 2), size / 2);//right_down

	
	if ((arr[0] == 10) && (arr[1] == 10) && (arr[2] == 10) && (arr[3]== 10)) {
		return 10;
	}
	else if ((arr[0] == 20) && (arr[1] == 20) && (arr[2] == 20) && (arr[3] == 20)) {
		return 20;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (arr[i] == 10) {
				blue++;
			}
			else if (arr[i] == 20) {
				white++;
			}
			
		}
		return 0;
		//return 1000; 리턴을 해주니깐 시간초과 안뜸.
		
	}

}


void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			paper[i][j] = -1;
		}
	}
}
int main() {
	cin >> n;
	init();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	f(0,0,n);

	cout << white << endl;
	cout << blue << endl;
	
}