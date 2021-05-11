#include <iostream>

using namespace std;
int a;
int n[100000] = { 0 };

int f(int left, int right) {
	if (left == right) {
		return n[left];
	}

	int mid = (left + right) / 2;

	//
	int isMax = max(f(left, mid), f(mid + 1, right));


	int mid2 = mid + 1;

	int Max = max(n[mid], n[mid+1]);

	int i = mid, j = mid2;

	while (i > left || j < right) {
		
		int mm = min(n[i], n[j]);
		int ll = max(n[i], n[j]);
		int go = mm * (j - i + 1);

		int testmax = max(go, ll);

		if (testmax == ll) {
			j++;
			Max += Max;
		}
		else if (testmax == go) {
			i--;
			j++;
		}



	}

	return isMax;
}

int main() {
	while (1) {
		
		cin >> a;
		if (a == 0)
			return 0;
	
		for (int i = 0; i < a; i++) {
			cin >> n[i];
		}

		//a 
		f(0, a - 1);
			

	}
	
}