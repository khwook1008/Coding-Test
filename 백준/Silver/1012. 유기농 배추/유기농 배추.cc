//1012 실버2 유기농배추
//BFS의 횟수를 찾아라
#include <bits/stdc++.h>
using namespace std;

int board[51][51];
int vis[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> Q;

int main(){
    int T, M, N, K;
    cin >> T;
    while(T--){
        cin >> M >> N >> K;
        int x, y;
        for(int i = 0; i < K; i++){ //배추밭 입력 받기
            cin >> x >> y;
            board[y][x] = 1; //입력 뒤집히는 것 유의
        }
        int answer = 0;
        for(int i = 0; i < N; i++){//세로
            for(int j = 0; j < M; j++){//가로
                if(board[i][j] == 1 && !vis[i][j]){
                    //BFS
                    vis[i][j] = 1;
                    Q.push({i, j});
                    while(!Q.empty()){
                        auto cur = Q.front();
                        Q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if(nx < 0 || nx >= N || ny < 0 || ny >= M){
                                continue;
                            }
                            if(vis[nx][ny] == 1 || board[nx][ny] != 1){
                                continue;
                            }
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                    answer++;
                }
            }
        }
        cout << answer << '\n';
        for(int i = 0; i < N; i++){
            fill(board[i], board[i]+M, 0);
            fill(vis[i], vis[i]+M, 0);
        }
    }

    return 0;
}