#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        fill(dist1[i], dist1[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);
    }
    for (int i = 0; i < n; i++){
        cin >> board[i];
    }
    queue<pair<int, int>> Q1;
    queue<pair<int, int>> Q2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == 'F'){
                Q1.push({i, j});
                dist1[i][j] = 0; //시작점 0
            }
            if (board[i][j] == 'J'){
                Q2.push({i, j});
                dist2[i][j] = 0; //시작점 0
            }
        }
    }
    // 불에 대한 BFS
    while (!Q1.empty())
    {
        auto cur = Q1.front();
        Q1.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) // 범위 밖
                continue;
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') //방문 || 벽
                continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }

    // 지훈이에 대한 BFS
    while (!Q2.empty())
    {
        auto cur = Q2.front();
        Q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            { // 범위 나가면 탈출 성공, 큐에 거리 순으로 들어가므로 최초에 탈출 시간 출력
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') //방문 || 벽                             
                continue;
            
            //if (dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)만 있으면 안될까?
            //불이 도달해야하고 && 불의 전파시간 이상이면 죽으니까 가면 안됨
            //불이 벽에 막혀 안 도달하면 (-1) 이고 뒤에 조건 무조건 만족 (dist1[nx][ny] != -1) 필요함
            // 3 4
            // ###F
            // oJ#o
            // ###o
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
                continue; 
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE"; // 여기에 도달했다는 것은 탈출에 실패했음을 의미.
}