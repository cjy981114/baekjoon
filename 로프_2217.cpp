#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int rnum;
vector<int> rope(100000,0) ;
int main() {

	cin >> rnum;

	for (int i = 0; i < rnum; i++) {
		cin >> rope[i];
	}

	sort(rope.begin(), rope.begin()+rnum);

	int findMax = 0;
	for (int i = 0; i < rnum; i++) {
		findMax = max(findMax, rope[i] * (rnum - i));
	}

	cout << findMax << endl;
}