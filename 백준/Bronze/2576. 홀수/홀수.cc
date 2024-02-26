#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    int sum = 0;
    int min = 0;
    
    for(int i = 0; i < 7; i++){
        cin >> N;
        if(N % 2){
            sum += N;
            if(min == 0){
                min = N;
            }
            if(N < min){
                min = N;
            }
        }
    }
    
    if(sum == 0){
        cout << -1;
    }
    else{
        cout << sum <<"\n"<<min;
    }
    
    return 0;
}
