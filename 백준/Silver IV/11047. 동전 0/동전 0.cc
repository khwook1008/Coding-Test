#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {0,};
    
    int N, K;
    int answer = 0;
    
    cin >> N >> K;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    for(int i = N-1; i >= 0; i--){
        answer += K / arr[i];
        K %= arr[i];
    }
    
    cout << answer << '\n';
    
    return 0;
}