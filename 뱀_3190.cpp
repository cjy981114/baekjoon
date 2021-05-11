#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n;
int board[102][102] = {0};
int k;


int dir=3;
queue<int> goTime;
queue<char> goDir;
int takeTime = 0;

int way[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

queue<pair<int, int>> snake;
//-1 벽 1 사과 2 뱀 꼬리
void playGame() {
	dir = 3;
	snake.push(make_pair(1, 1));
	int i = 1;
	int j = 2;
	while (board[i][j]!=-1 && board[i][j]!=2) {//벽이 아니거나 몸이 아니어야 함
		takeTime++;
		if (!goTime.empty() && goTime.front() == takeTime) {//방향 바꾸기
			char dd = goDir.front();
			if (dd == 'D') {//오른쪽
				if (dir == 0) {
					dir = 3;
				}
				else {
					dir--;
				}

			}
			else if (dd == 'L') {//왼쪽
				if (dir == 3) {
					dir = 0;
				}
				else {
					dir++;
				}
			}
			goTime.pop();
			goDir.pop();
		}

		int mov_x = way[dir][0];
		int mov_y = way[dir][1];

		if (board[i][j] == 0) {//현재 빈칸
			int tail_x = snake.front().first;
			int tail_y = snake.front().second;
			board[tail_x][tail_y] = 0;

			snake.pop();
			snake.push(make_pair(i, j));
			board[i][j] = 2;

			i += mov_x;
			j += mov_y;

		}
		else if (board[i][j] == 1) {//현재 사과 
			board[i][j] = 2;
			snake.push(make_pair(i, j));
			i += mov_x;
			j += mov_y;
		}
		
	}

	cout << takeTime+1 << endl;
}

	


int main() {
	
	cin >> n;
	cin >> k;
	
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			if (i == 0 || i == n + 1) {
				board[i][j] = -1;
			}

			if (j == 0 || j == n + 1) {
				board[i][j] = -1;
			}
		}
	}

	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		board[a][b] = 1;
	}

	cin >> dir;

	char c;
	for (int i = 0; i < dir; i++) {
		cin >> a >> c;
		goTime.push(a);
		goDir.push(c);
	}

	playGame();

	return 0;
}