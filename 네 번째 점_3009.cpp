#include <iostream>

using namespace std;

int main() {
	int spot[3][2];
	int ans_x=0, ans_y=0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> spot[i][j];
		}
	}

	int go_x = -1, go_y = -1;
	for (int i = 0; i < 2; i++) {
		if (spot[2][0] == spot[i][0]) {
			go_x = i;
		}
		if (spot[2][1] == spot[i][1]) {
			go_y = i;
		}
	}

	if (go_x == -1) {
		ans_x = spot[2][0];
	}
	else if (go_x == 0)
		ans_x = spot[1][0];
	else
		ans_x = spot[0][0];

	if (go_y == -1) {
		ans_y = spot[2][1];
	}
	else if (go_y == 0)
		ans_y = spot[1][1];
	else
		ans_y = spot[0][1];

	cout << ans_x << " " << ans_y << endl;

	return 0;

}