#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, left, mid, right; // 이진탐색
    
    while(1){
        cin >> n;
        if(n == 0){     //0입력 시 종료
            return 0;
        }
        while(n){
            int mid = 25;
            if(n == 25){
                if(n == mid){
                    cout << mid << endl;
                }
            }
            else{
                left = 1;
                right = 50;
                while(mid != n){
                    cout << mid << " ";
                    if(mid > n){
                        right = mid - 1;
                    }
                    else{
                        left = mid + 1;
                    }
                    mid = (left + right) / 2;
                }
                cout << mid << '\n';
            }
            break;
        }
    }
    return 0;
}
