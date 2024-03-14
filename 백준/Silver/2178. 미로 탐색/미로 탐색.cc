#include <bits/stdc++.h>
using namespace std;

string board[502];      //1이 길이 있는 곳, 0이 길이 없는 곳
int dist[502][502];     //거리를 저장, -1이 아니면 방문했다는 표시도 확인 가능

int n, m;                   //행, 렬

int dx[4] = {1, 0, -1, 0}; //방향 하, 우, 상, 좌 순으로 탐색할 것이다.
int dy[4] = {0, 1, 0, -1}; 

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

    //지도 입력
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    //거리를 입력할 판을 -1로 초기화 -> 방문과 거리를 모두 표시할 수 있음
    fill(&dist[0][0], &dist[n-1][m], -1);
    // cout << '\n';
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << dist[i][j];
    //     }
    //     cout << '\n';
    // }

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0] = 1;
    while(!Q.empty()){  //큐가 비면 종료
        auto cur = Q.front();
        Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){ // 보드의 범위를 벗어날 경우
                continue;
            }
            if(dist[nx][ny] >= 0 || board[nx][ny] != '1'){ //방문 및 거리 표시했고, 길이 아닐 경우
                continue;
            }
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }    
    cout << dist[n-1][m-1];
}