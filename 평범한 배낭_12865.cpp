#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

int weight[101] = { 0 };
int value[101]={0};

int d[101][100001] = { 0 };

int main() {

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> weight[i] >> value[i];
		
	}

	int tsum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (weight[i] <= j) {
				d[i][j] = max(d[i - 1][j], d[i-1][j - weight[i]] + value[i]);
			}
			else {
				d[i][j] = d[i - 1][j];
			}
		}
		

	}


	
	cout << d[N][K] << endl;

	
	
}