#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int M, N, root;
    int count = 0;
    cin >> M >> N;
    
    for(int i = M; i <= N; i++){
        root = (int)sqrt(i); 
        //전체를 다 돌아가면서 나누어버리면 시간초과 발생
        //제곱근이하의 값들을 돌아가면서 나누어서 확인하는 과정으로 시간초과 해결
        for(int j = 2; j <= root; j++){
            if(i % j == 0){
                count++;
                break;
            }
        }
        
        if(count == 0 && i != 1){
            cout << i << "\n";
        }
        count = 0;
    }

    return 0;
}
