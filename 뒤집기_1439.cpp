#include <iostream>
#include <cstring>

using namespace std;

int main() {
	string s;
	int ans = 0;
	cin >> s;

	int cnt_one = 0;
	int cnt_zero = 0;

	if (s[0] == '0') {
		cnt_zero++;
	}
	else {
		cnt_one++;
	}

	for (long long i = 1; i < s.size(); i++) {
		if (s[i-1]!=s[i]) {
			if (s[i] == '0') {
				cnt_zero++;

			}
			else {
				cnt_one++;
			}
		}
	}
	
	cout << min(cnt_zero, cnt_one) << endl;
}