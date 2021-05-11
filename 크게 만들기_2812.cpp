#include <iostream>
//#include <deque>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	string word;
	vector<char> find;
	
	cin >> n >> k;
	cin >> word;
	int fsize = n - k;
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		while (k > 0 && !find.empty() && find.back()<word[i]){
			find.pop_back();
			k--;
		}

		find.push_back(word[i]);
	}

	for (int i = 0; i < fsize; i++)
		cout << find[i];

	return 0;
}