//10026 골드5 적록색약
//N X N 그리드에 R, G, B 중 하나를 색칠한 그림이 있다.
//그림은 같은 색으로 몇개의 구역으로 나누어져있다.
//같은 색상이 상하좌우로 인접해 있는 경우 두글자는 같은 구역에 속한다.
//R, G이 붙어 있으면 같은 구역으로 인식함.
//=> 적록색약은 R, G는 같은 구역으로 인지하고 BFS, 정상인은 R, G, B 세구역으로 인지 
#include <bits/stdc++.h>
using namespace std;

char board[102][102];
//string board[102];
int vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N; // 가로, 세로

int answer1, answer2; //정상, 색맹

void bfs(int i, int j){
    queue<pair<int, int>> Q;
    vis[i][j] = 1; //시작점 방문 표시
    Q.push({i, j}); //시작점 push
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N){
                continue;
            }
            if(vis[nx][ny] == 1 || board[nx][ny] != board[i][j]){ //방문, 색 다르면 X
                continue;
            }
            vis[nx][ny] = 1; //방문 표시
            Q.push({nx, ny});
        }
    }
}

int main(){
    cin >> N;
    //board 채우기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    // for (int i = 0; i < N; i++){
    //     cin >> board[i];
    // }

    //정상인 먼저
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!vis[i][j]){
                bfs(i, j);
                answer1++;
            }
        }
    }
    //정상인 종료 후 vis 초기화 및 board R, G 통일
    fill(&vis[0][0], &vis[N-1][N], 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] == 'G'){
                board[i][j] = 'R';
            }
        }
    }

    //색맹
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!vis[i][j]){
                bfs(i, j);
                answer2++;
            }
        }
    }
    cout << answer1 << ' ' << answer2;
    return 0;
}