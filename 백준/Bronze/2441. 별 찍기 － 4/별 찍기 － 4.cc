#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;

    cin >> N;
    
    for(int i = 0; i < N; i++){
        int j = 0;
        for(j = 0 ; j < i; j++){
            cout << ' ';
        }
        for( ; j < N; j++){
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}