// 10807 브론즈5 개수 세기
// 구현
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, num;
    int arr[100] = {0,};
    int ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    cin >> num;

    for(int i = 0; i < N; i++){
        if(num == arr[i]){
            ans++;
        }
    }
    cout << ans;

    return 0;
}