#include <iostream>
#include <string>
using namespace std;

int n;
int arr[64][64];

string f(int a, int b, int size) {
	if (size == 1) {
		if (arr[a][b] == 1) {
			return "1";
		}
		else if (arr[a][b] == 0) {
			return "0";
		}
	}

	string ret[4];
	ret[0] = f(a, b, size / 2);//1. left_up
	ret[1] = f(a, b + (size / 2), size / 2);//2. right_up
	ret[2] = f(a + (size / 2), b, size / 2); //3. left_down
	ret[3] = f(a + (size / 2), b + (size / 2), size / 2); //4. right_down

	if ((ret[0] == "1") && (ret[1] == "1") && (ret[2] == "1") && (ret[3] == "1")) {
		return "1";
	}
	else if ((ret[0] == "0") && (ret[1] == "0") && (ret[2] == "0") && (ret[3] == "0")) {
		return "0";
	}
	else {
		string test = "("+ret[0]+ret[1]+ret[2]+ret[3]+")";
		return test;
	}


}
int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &arr[i][j]); 
		}
	}
	string ret = f(0, 0, n);
	cout << ret << endl;
	return 0;
}