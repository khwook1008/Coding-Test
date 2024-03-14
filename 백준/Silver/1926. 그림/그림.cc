#include <bits/stdc++.h>
using namespace std;

int board[502][502];    //1이 그림이 있는 곳, 0이 그림이 없는 곳
bool vis[502][502];     //방문 여부를 저장  

int n, m;                   //행, 렬

int dx[4] = {1, 0, -1, 0}; //방향 하, 우, 상, 좌 순으로 탐색할 것이다.
int dy[4] = {0, 1, 0, -1}; 

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

    //입력 받을 도화지를 만들고 그림들을 입력 받는다. 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    int mx = 0;     //그림 넓이 최댓값
    int num = 0;    //그림의 개수
    //그림이 하나가 아니기 때문에 이중 for문을 통해 각 그림의 시작점을 찾아줘야함
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0 || vis[i][j]){ //그림 없거나, 이미 방문한 곳 넘어감
                continue;
            }
            //새로운 그림의 시작점 찾고 시작 (i, j)
            num++;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;      //(i, j)를 시작점으로 BFS 시작 (시작점을 방문했다)
            Q.push({i, j});
            int area = 0;       //넓이는 그림이 하나 끝날때마다 초기화 필요
            while(!Q.empty()){  //큐가 비면 종료
                area++;         //큐 pop할때 마다 넓이 1씩 증가
                pair<int, int> cur = Q.front();
                Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m){ // 보드의 범위를 벗어날 경우
                        continue;
                    }
                    if(vis[nx][ny] || board[nx][ny] != 1){ //이미 방문, 그림 아닐 경우
                        continue;
                    }
                    vis[nx][ny] = 1; //방문했다고 표시
                    Q.push({nx, ny});
                }
            }
            mx = max(mx, area); // 한 그림 끝나면 최대 넓이 저장
        }
    }
    cout << num << '\n' << mx;
}