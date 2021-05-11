#include <iostream>

using namespace std;

int arr[1001] = { 0 };
int num = 0;
int dp_up[1001] = { 0 };
int dp_down[1001] = { 0 };
int t[1001] = { 0 };
void f() {	//flag=1 증가 / 0 감소
	
	dp_up[1]=1;
	for (int i = 2; i <= num; i++) {
		dp_up[i] = 1;
		for (int j = i -1; j >0; j--) {
			if (arr[i] > arr[j]) {
				dp_up[i] = max(dp_up[i],dp_up[j] + 1);
			}
		}
	}
	
}

void f2() {	//flag=1 증가 / 0 감소


	dp_down[num] = 1;

	for (int i = num-1; i >0; i--) {
		dp_down[i] = 1;
		for (int j = i+1; j <=num; j++) {
			if (arr[i] > arr[j]) {
				dp_down[i] = max(dp_down[i], dp_down[j] + 1);
			}
		}
	}
}



int main() {
	cin >> num;

	for (int i = 1; i <= num; i++) {
		cin >> arr[i];
	}

	f();
	f2();
	
	int mmax = 0;
	for (int i = 1; i <= num; i++) {
		t[i] = dp_up[i] + dp_down[i];
		mmax = max(mmax, t[i] - 1);

	}

	cout << mmax << endl;
	cout << endl;
}