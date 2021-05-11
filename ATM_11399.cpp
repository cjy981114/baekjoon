#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0;
vector<int> people;
int main() {
	cin >> num;

	int a=0;
	for (int i = 0; i < num; i++) {
		cin >> a;
		people.push_back(a);
	}

	sort(people.begin(), people.end());

	int sum = people[0];
	for (int i = 1; i < num; i++) {
		people[i] = people[i] + people[i-1];	
		sum += people[i];
	}

	cout << sum << endl;
}