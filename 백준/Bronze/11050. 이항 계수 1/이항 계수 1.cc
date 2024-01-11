#include <iostream>

using namespace std;

int factorial(int num){
    int cal = 1;
    if(num == 0){
        cal = 1;
    }
    else{
        for(int i = num; i > 0; i--){
            cal *= i;
        }
    }
    
    return cal;
}

int main()
{
    int N, K;
    
    cin >> N >> K;
    
    cout << factorial(N) / (factorial(N-K) * factorial(K));
    return 0;
}
