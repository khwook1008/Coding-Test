#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int check[2000001];
int N, X;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cin >> X;
    
    for(int i = 0; i < N; i++){  
        if(X-arr[i] > 0 && check[X-arr[i]]){
            ans++;
        }
        check[arr[i]] = 1;
    }
    cout << ans;
    
    return 0;
}