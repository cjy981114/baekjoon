#include <iostream>

using namespace std;

int n;
int arr[2001] = { 0 };
int d[2001][2001] = { 0 };
int qnum;

int f(int left, int right) {

	if (left >= right) {
		return 1;
	}

	int& ret = d[left][right];

	if (ret != -1) {
		return ret;
	}

	if (arr[left] != arr[right]) {
		ret = 0;
		
		return ret;
	}
	else {
		ret = f(left + 1, right - 1);
		return ret;
	}

}


int main() {
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d" ,&arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = -1;
		}
	}
	scanf_s("%d", &qnum);

	int a, b;
	for (int i = 1; i <= qnum; i++) {
		scanf_s("%d %d", &a, &b);
		
		printf("%d\n", f(a, b));
		
	}




}