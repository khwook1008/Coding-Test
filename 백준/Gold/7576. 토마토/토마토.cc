
//토마토
//하루가 지나면 익은 토마토들의 인접한 상하좌우에 있는 안 익은 토마토들도 익는다.
//며칠이 지나면 다 익을까, 최소일수는?
//0 : 익지 않은 토마토, -1 : 토마토 없음, 1 : 익은 토마토
//=>익은 토마토를 기준으로 동시에 BFS를 돌린다.
#include <bits/stdc++.h>

using namespace std;

int board[1002][1002];
int dist[1002][1002];
int n, m, mx;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    queue<pair<int, int>> Q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){//익은 토마토들은 BFS의 시작점이 된다.
                Q.push({i, j});
            }
            if(board[i][j] == 0){//익지 않은 토마토들은 가야할 길이기 때문에 -1로 표시
                dist[i][j] = -1; //어차피 나머지 것들은 전역변수 초기화 0
            }
        }
    }
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){ //범위 확인
                continue;
            }
            if(dist[nx][ny] >= 0){ //익지 않은 토마토는 -1, 그 곳으로만 가면 됨. 이외는 안가도 됨
                continue;
            }
            dist[nx][ny] = dist[cur.first][cur.second] + 1; //다음날 부터 1이기 때문에 추가 작업X
            Q.push({nx,ny});
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[i][j] == -1){//하나라도 안 익은게 있으면 -1 출력
                cout << -1;
                return 0;
            }
            mx = max(dist[i][j], mx);//다 익었으면, 모두 익을 수 있는 시간 출력
        }
    }
    cout << mx;
    return 0;
}