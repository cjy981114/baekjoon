#include <iostream>

using namespace std;

int n;
int arr[11] = { 0 };
int calc[4] = { 0 };

int ans[11] = { 0 };
int ans1=-1000000001;
int ans2=1000000001;
void f(int cnt) {
	if (cnt == n-1) {
		ans1 = max(ans1, ans[cnt]);
		ans2 = min(ans2, ans[cnt]);
		return;
	}

	int curr_num = ans[cnt];
	for (int i = 0; i < 4; i++) {
		if(calc[i]>0){
			if (i == 0) {
				ans[cnt + 1] = curr_num + arr[cnt + 1];
				calc[i]--;
				f(cnt + 1);
				calc[i]++;
			}
			else if (i == 1) {
				ans[cnt + 1] = curr_num - arr[cnt + 1];
				calc[i]--;
				f(cnt + 1);
				calc[i]++;
			}
			else if (i == 2) {
				ans[cnt + 1] = curr_num * arr[cnt + 1];
				calc[i]--;
				f(cnt + 1);
				calc[i]++;
			}
			else if (i == 3) {
				ans[cnt + 1] = curr_num / arr[cnt + 1];
				calc[i]--;
				f(cnt + 1);
				calc[i]++;
			}
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	ans[0] = arr[0];

	for (int i = 0; i < 4; i++) {
		cin >> calc[i];
	}

	f(0);

	cout << ans1 << endl;
	cout << ans2 << endl;
}