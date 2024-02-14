#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int answer = 0;

    cin >> N;
    
    int arr[N] = {0, };

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    //오래걸리는 놈을 뒤로 보내라
    sort(arr, arr + N);
    
    // 앞사람 걸리는 시간 + 자기 걸리는 시간
    // 첫번째놈은 모든 사람 시간에 영향을 줌(모든 사람 시간에 +)
    // 두번째놈은 첫번째 빼고 시간에 영향을 줌
    for(int i = 0; i < N; i++){
        answer += arr[i] * (N - i);
    }
    
    cout << answer;

    return 0;
}