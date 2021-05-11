#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int main() {
	cin >> n;

	int a;
	int mm = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}

	vector<int> li;

	for (int i = 0; i < n; i++) {
		if (li.empty()|| li.back() <arr[i])
			li.push_back(arr[i]);
		else {
			int a = lower_bound(li.begin(), li.end(), arr[i])-li.begin();
			li[a] = arr[i];
		}


	}
	
	cout << li.size() << endl;
	
}