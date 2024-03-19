// 7569 골드5 토마토(3차원)
// 3차원 토마토 상자, 가로 M, 세로 N, 높이 H, 상자의 1:익은, 0:안 익은, -1:빈 곳
// 위, 아래, 오른쪽, 왼쪽, 앞, 뒤 6방향으로 익어나간다. 최소 일수는?

#include <bits/stdc++.h>
using namespace std;

int M, N, H; //가로, 세로, 높이

// 위, 아래, 오른쪽, 왼쪽, 앞, 뒤
int dx[6] = {0, 0, 0, 0, 1, -1}; //N 
int dy[6] = {0, 0, 1, -1, 0, 0}; //M
int dz[6] = {1, -1, 0, 0, 0, 0}; //H

int box[103][103][103];
int vis[103][103][103];

queue<tuple<int, int, int>> Q; // 3개일때 tuple 사용

int main(){
    cin >> M >> N >> H; //가로 세로 높이
    //box와 vis에 채워넣기
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                int tmp;
                cin >> tmp;
                box[j][k][i] = tmp;         //세로 가로 높이 (행, 열, 높이)
                if (tmp == 1){              //익은 곳 BFS의 시작점으로 설정
                    Q.push({j, k, i});
                }
                if (tmp == 0){              //안 익은 곳은 가야함 -1로 설정, 추후 방문
                    vis[j][k][i] = -1;
                }
            }
        }
    }
    //BFS 시작
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur; //묶여있는 것을 압축해제
        for(int dir = 0; dir < 6; dir++){
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            //세로 가로 높이 각각 순서 유의
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H){
                continue;
            }
            if(vis[nx][ny][nz] >= 0){ //안 익은 곳만 가야함
                continue;
            }
            vis[nx][ny][nz] = vis[curX][curY][curZ] + 1;
            Q.push({nx, ny, nz});
        }
    }
    //안 익은거 없나 검사 및 최대 시간 검색 시작
    int answer = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(vis[j][k][i] == -1){ //i, j, k 순서 유의
                    cout << -1;
                    return 0;
                }
                answer = max(answer, vis[j][k][i]);
            }
        }
    }
    cout << answer;
    return 0;
}