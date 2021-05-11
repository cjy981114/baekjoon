#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int alp[26] = { 0 };
char cnt[11] = { 0 };
bool comp(int i, int j) {
	return i > j;
}

int main() {
	cin >> n;

	for (int a = 0; a < n; a++) {
		string str;
		cin >> str;
		int ssize = str.size() - 1;
		int gnum = 0;
		for (int i = 0; i < str.size(); i++) {
			gnum = 1;
			gnum *= pow(10, ssize);
			alp[str[i] - 'A'] += gnum;
			ssize--;
		}
	}
	
	sort(alp, alp+26, comp);

	int num = 9;
	int sum = 0;
	for (int i = 0; i < 26; i++) {
		if (alp[i] != 0) {
			sum += alp[i] * num;
			num--;
		}
		else
			break;
	}
	cout << sum << endl;
	return 0;
}