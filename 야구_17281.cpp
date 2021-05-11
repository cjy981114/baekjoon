#include <iostream>
#include <vector>
using namespace std;
int n;
int e[50][10];//이닝 별 타자 득수

int base[5] = {0};
int num[10] = {0};
int test_max = 0;

void countGame() {
	
	int game_Strike = 0;
	int game_Score = 0;
	int j = 1;

	for (int i = 0; i < n; i++) {//이닝 별
		while (1) {
			if (j == 10) {
				j = 1;
			}
			int hitter = num[j];
			int move_base = e[i][hitter];//이동해야 하는 베이스 수

			if (move_base == 0) {//아웃
				game_Strike++;
				if (game_Strike == 3) {//3진 아웃
					game_Score += base[4];
					j = j+1;
					base[0] = base[1] = base[2] = base[3] = base[4] = game_Strike = 0;//3아웃 -> 모든 베이스 비워야했다..
					break;
				}
			}
			else {//1 2 3 4 일 때 
				for (int b = 3; b >= 1; b--) {//base 이동
					if (base[b] != 0) {//b번 base에 사람이 있을 경우
						if ((b + move_base) >= 4) {
							base[4]++;
							base[b] = 0;
						}
						else {
							base[b + move_base] = 1;
							base[b] = 0;
						}
					}
				}
				if (move_base == 4) {
					base[4]++;
				}
				else {
					base[move_base] = 1;//j번째 선수 해당하는 base로 이동
				}
				
			}
			j++;
		}	
	}
	test_max = max(test_max, game_Score);
	return;
}


void f(int player) {

	if (player > 9) {
		countGame();
	}

	for (int i = 1; i <= 9; i++) {
		if (num[i] == -1) {
			num[i] = player;
			f(player + 1);
			num[i] = -1;
		}
	}
	return;
}


int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> e[i][j];
		}
	}
	for (int i = 1; i <= 9; i++) {
		num[i] = -1;
	}
	num[4] = 1;	//4번 타자는 1번 선수
	f(2);
	cout << test_max << endl;
	return 0;
}