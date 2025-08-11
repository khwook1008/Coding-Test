// 13300 브론즈2 방 배정
// 수학 구현
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K, ans = 0;
    //학년 1~6 index
    int arr[2][7] = {0, };

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b]++;
    }
    
    //성별, 학년 동일
    for(int i = 0; i < 2; i++){
        for(int j = 1; j < 7; j++){
            ans += arr[i][j] / K;
            //딱 안 맞을때 방하나 추가
            if(arr[i][j] % K){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}