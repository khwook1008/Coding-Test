#include <bits/stdc++.h>
using namespace std;

int dist[100002];
int n, k;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> k;

    fill(dist, dist + 100001, -1);

    dist[n] = 0; //첫 방문 0

    queue<int> Q;

    Q.push(n);

    //BFS 진행
    while(dist[k] == -1){ //동생의 위치에 도달하여 몇초 후인지 넣어주면 종료
        int cur = Q.front();
        Q.pop();
        for(int i : {cur - 1, cur + 1, cur * 2}){ //ranged-based for문 
            if(i < 0 || i > 100000){ //범위 넘어가면
                continue;
            }
            if(dist[i] != -1){ //이미 방문했으면
                continue;
            }
            dist[i] = dist[cur] + 1;
            Q.push(i);
        }
    }
    cout << dist[k];
}