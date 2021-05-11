#include <iostream>
#include <string>
using namespace std;

string A;
string B;

int d[1001][1001] = { 0 };
int main() {

	cin >> A >> B;

	int z = 1;
	int i = 0;
	int j = 0;
	int cnt = 0;

	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			if (A[i] == B[j]) {
				d[i + 1][j + 1] = d[i][j] + 1;
			}
			else {
				d[i + 1][j + 1] = max(d[i][j + 1], d[i + 1][j]);
			}
		}
	}



	cout << d[A.size()][B.size()] << endl;
}