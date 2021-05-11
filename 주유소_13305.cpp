#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cityNum = 0;
	vector<unsigned long long int> city;
	
	vector<unsigned long long int> distance;
	vector<unsigned long long int> cost;
	
	cin >> cityNum;

	unsigned long long int a;
	for (int i = 0; i < cityNum - 1; i++) {
		cin >> a;
		distance.push_back(a);
	}


	unsigned long long int b;
	for (int i = 0; i < cityNum; i++) {//ÁÖÀ¯¼Ò
		cin >> b;
		city.push_back(b);

	}

	unsigned long long int stay = city[0];

	for (int i = 0; i < cityNum-1; i++) {
		if (stay > city[i + 1]) {
			cost.push_back(stay * distance[i]);
			stay = city[i + 1];
		}
		else {
			cost.push_back(stay * distance[i]);
		}
	}

	unsigned long long int sum = 0;
	for (int i = 0; i < cityNum - 1; i++) {
		sum += cost[i];
	}

	cout << sum << endl;
}