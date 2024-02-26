#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[4] = {0, };
    int num = 0;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cin >> arr[j];
            num += arr[j];
        }
        
        if(num == 4){
            cout << 'E';
        }
        else if(num == 3){
            cout << 'A';
        }
        else if(num == 2){
            cout << 'B';
        }
        else if(num == 1){
            cout << 'C';
        }
        else if(num == 0){
            cout << 'D';
        }
        
        num  = 0;
        cout << '\n';
    }
    return 0;
}
