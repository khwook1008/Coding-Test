#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[9];
    int sum = 0;
    
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
    sort(arr, arr + 9); // 오름차순 정렬
    
    for(int i = 0; i < 8; i++){                 //9개중에 2개를 선택하는 과정
        for(int j = i + 1; j < 9; j++){
            if(sum - (arr[i] + arr[j]) == 100){ //전체 합에서 2명 뺀게 100일때
                for(int k = 0; k < 9; k++){     //뺀거들 출력X
                    if(k != i && k != j){
                        cout << arr[k] << '\n';
                    }
                }
                return 0;                       //가능한 정답이 여러 가지인 경우에는 아무거나 출력한다.
            }
        }
    }
    return 0;
}