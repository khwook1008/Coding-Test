//7562 실버1 나이트의 이동
//체스판 위에 나이트 하나. 한번에 이동할 수 있는 칸은 3칸째의 거리
//이동하려는 칸이 주어지면 몇번 움직여서 갈 수 있을까? 
//한변의 길이 L(4 <= L <= 300) L X L 의 체스판
//=>현재 위치를 BFS의 시작점으로 잡고 BFS 진행, 0으로 시작하여 방문할때마다 숫자++
//BFS 진행 후 도착지의 dist 값을 구한다.
#include <bits/stdc++.h>
using namespace std;

int T, L, x, y, gx, gy; 
//나이트가 갈 수 있는 위치들
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2}; //행
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1}; //열
int dist[302][302];

queue<pair<int, int>> Q;

int main(){
    cin >> T;
    while(T--){
        cin >> L;
        for(int i = 0; i < L; i++){
            for(int j = 0; j < L; j++){
                dist[i][j] = -1;
            }
        }
        cin >> x >> y;          //시작점 입력
        cin >> gx >> gy;        //목적지 입력

        if(x == gx && y == gy){ //시작점 목적지 동일하면 0으로 출력 BFS 안해도 됨
            cout << 0 << '\n';
            continue;
        }
        
        //BFS 시작
        dist[x][y] = 0;         //시작점 방문 숫자 0
        
        Q.push({x, y});

        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();

            for(int dir = 0; dir < 8; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= L || ny < 0 || ny >= L){
                    continue;
                }
                if(dist[nx][ny] >= 0){ //방문한 곳들은 가지말아야함
                    continue;
                }
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                if(nx == gx && ny == gy){
                    cout << dist[nx][ny] << '\n';
                    break;
                }
                Q.push({nx, ny});
            }
        }
    }
    return 0;
}