#include <iostream>
#include <vector>
using namespace std;
int n;
int e[50][10];//�̴� �� Ÿ�� ���

int base[5] = {0};
int num[10] = {0};
int test_max = 0;

void countGame() {
	
	int game_Strike = 0;
	int game_Score = 0;
	int j = 1;

	for (int i = 0; i < n; i++) {//�̴� ��
		while (1) {
			if (j == 10) {
				j = 1;
			}
			int hitter = num[j];
			int move_base = e[i][hitter];//�̵��ؾ� �ϴ� ���̽� ��

			if (move_base == 0) {//�ƿ�
				game_Strike++;
				if (game_Strike == 3) {//3�� �ƿ�
					game_Score += base[4];
					j = j+1;
					base[0] = base[1] = base[2] = base[3] = base[4] = game_Strike = 0;//3�ƿ� -> ��� ���̽� ������ߴ�..
					break;
				}
			}
			else {//1 2 3 4 �� �� 
				for (int b = 3; b >= 1; b--) {//base �̵�
					if (base[b] != 0) {//b�� base�� ����� ���� ���
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
					base[move_base] = 1;//j��° ���� �ش��ϴ� base�� �̵�
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
	num[4] = 1;	//4�� Ÿ�ڴ� 1�� ����
	f(2);
	cout << test_max << endl;
	return 0;
}