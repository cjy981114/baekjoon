#include <iostream>
#include <vector>
using namespace std;

bool arr[1000001];
int m, n;
vector<int> gget;

void making(int num) {
	for (int i = num*2; i <= n; i += num) {
		arr[i] = true;
	}
}
void f(int num) {
	arr[1] = true;
	for (int i = 2; i <= n; i++) {
		if (arr[i] == false) {
			making(i);
		}
	}
}
int main() {

	scanf("%d %d", &m, &n);
	//cin >> m >> n;
	f(1);

	for (int i = m; i <= n; i++) {
		if (arr[i] == false)
			printf("%d\n", i);
			//cout << i << endl;
	}

	return 0;
}