#include <iostream>

using namespace std;
int step=0;
int stair[301] = { 0 };
int s[301] = {0};
int f() {

	s[1] = stair[1];
	s[2] = stair[1] + stair[2]; 

	for (int i = 3; i <= step; i++) {
		s[i] = max(s[i - 2] + stair[i], s[i - 3] + stair[i - 1] + stair[i]);
	}

	return s[step];
}

int main() {
	cin >> step;

	for (int i = 1; i <= step; i++) {
		cin >> stair[i];
	}

	
	int ret = f();
	cout << ret << endl;


	//s[3] = max(s[1] + stair[3], s[0]+stair[2] + stair[3]); //35

	//s[4] = max(s[2] + stair[4],s[1]+stair[3]+stair[4]); //45

	//s[5] = max(s[3] + stair[5], s[2] + stair[4]+stair[5]); //


}