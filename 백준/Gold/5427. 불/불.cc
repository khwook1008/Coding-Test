// 5427 골드4 불
// 상근이는 빈공간과 벽으로 이루어진 건물, 불이 남
// 불이 여러 곳에서 발생, 불들의 시작점들에서 BFS 진행
// 상근이 시작점에서 BFS 진행
#include <bits/stdc++.h>
using namespace std;

//[행][열]
int board[1002][1002];
int visF[1002][1002];
int visS[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int T, W, H; // case, 가로, 세로
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--){
		queue<pair<int, int>> QF = {}; // 큐 비우기
		queue<pair<int, int>> QS = {};
		int escape = 0;
		cin >> W >> H;
		for (int i = 0; i < H; i++){
			fill(visF[i], visF[i] + W, 0); // 초기화
			fill(visS[i], visS[i] + W, 0);
		}
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				char c;
				cin >> c;
				if (c == '#')
					board[i][j] = -1;
				else{
					if (c == '@'){
						QS.push({i, j});
						visS[i][j] = 1;
					}
					else if (c == '*'){
						QF.push({i, j});
						visF[i][j] = 1;
					}
					board[i][j] = 0;
				}
			}
		}
		// 불의 BFS 시작
		while (!QF.empty()){
			auto cur = QF.front();
			QF.pop();
			for (int dir = 0; dir < 4; dir++){
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || H <= nx || ny < 0 || W <= ny)
					continue;
				if (board[nx][ny] == -1)
					continue;
				if (visF[nx][ny])
					continue;
				visF[nx][ny] = visF[cur.first][cur.second] + 1;
				QF.push({nx, ny});
			}
		}
		// 상근 BFS 시작
		while ((!QS.empty()) && (!escape)){
			auto cur = QS.front();
			QS.pop();
			for (int dir = 0; dir < 4; dir++){
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W){ // 범위 밖이면 탈출
					escape = 1;
					cout << visS[cur.first][cur.second] << '\n';
					break; // for문 탈출 후 while문 종료
				}
				if(visS[nx][ny] > 0 || board[nx][ny] == -1){
					continue;
				}
				//불은 도달하지 못하는데 visF가 -1이기때문에 BFS를 진행안해서 문제 발생 가능
				//visF[nx][ny] > 0를 꼭 넣어줘야함(불이 있을때 못감)
				if(visF[nx][ny] != 0 && visF[nx][ny] <=  visS[cur.first][cur.second] + 1){
					continue;
				}
				visS[nx][ny] = visS[cur.first][cur.second] + 1;
				QS.push({nx, ny});
			}
		}
		if(!escape){
			cout << "IMPOSSIBLE" << '\n';
		}
	}
}
