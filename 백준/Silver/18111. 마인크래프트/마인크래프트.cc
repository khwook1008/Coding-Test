#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m,b;
int a[504][504];
int mintime = 987654321;
int height;
	
int main(){
    
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> b;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
		    //입력 받기
			cin >> a[i][j];
		}
	}
	
	for(int h = 0; h <= 256; h++){ //brute force 0 <= h <= 256
		int add = 0;
		int remove = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
			    //맞출 height보다 높으면 제거
				if(a[i][j] > h) {
					remove += a[i][j] - h;
				}
				//맞출 height보다 낮으면 쌓기
				else if(a[i][j] < h){
					add += h - a[i][j];
				}
			}
		}
		if(remove + b >= add) {
			int time = remove * 2 + add;
			if(mintime >= time){
				mintime = time;
				height = h;
			}
		}
	}
	cout << mintime << " " << height;
	return 0;
}
