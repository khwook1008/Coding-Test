#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int A, B, C, Prize;
    cin >> A >> B >> C;
    
    if(A == B && B == C){
        Prize = 10000 + A * 1000;
    }
    else if(A == B){
        Prize = 1000 + A * 100;
    }
    else if(A == C){
        Prize = 1000 + A * 100;
    }
    else if(B == C){
        Prize = 1000 + B * 100;
    }
    else{
        Prize = max({A, B, C}) * 100;
    }
    
    cout << Prize;
    return 0;
}
