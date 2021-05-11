#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> person;
int victory[50] = { 0 };
int num;
int main() {
	cin >> num;

	int a, b;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;

		person.push_back(make_pair(a, b));
	}


	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if ((person[i].first < person[j].first) && (person[i].second < person[j].second)) {
				victory[i] += 1;
			}
		}
	}

	for (int i = 0; i < num; i++) {
		cout << victory[i] + 1 << " ";
	}

	return 0;
}