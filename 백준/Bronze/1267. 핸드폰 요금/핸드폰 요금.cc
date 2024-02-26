#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int MTime = 0, YTime = 0; 
    int Time;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> Time;
        YTime += (Time / 30 + 1) * 10;
        MTime += (Time / 60 + 1) * 15;
    }
    
    if(YTime == MTime){ // 60 45
        cout << 'Y' << ' ' << 'M' << ' '<< YTime;
    }
    else if(MTime < YTime){
        cout << 'M' << ' ' << MTime;
    }
    else if(YTime < MTime){
        cout << 'Y' << ' ' << YTime;
    }
    return 0;
}