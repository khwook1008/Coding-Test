#include <iostream>
using namespace std;
int fibomem[41] = {0,1, };
int fibonacci(int N)
{
    if(N == 0 || N == 1){
        return fibomem[N];
    }
    else if(fibomem[N] == 0){
        fibomem[N] = fibonacci(N-1) + fibonacci(N-2);
    }
    
    return fibomem[N];
}
int main() {
    int N;
    cin >> N;
    
    int num;
    
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        if(num == 0){
            cout << "1 0" << '\n';
        }
        else{
            cout << fibonacci(num-1) << ' ' << fibonacci(num) << '\n';
        }
    }
    
    return 0;
}