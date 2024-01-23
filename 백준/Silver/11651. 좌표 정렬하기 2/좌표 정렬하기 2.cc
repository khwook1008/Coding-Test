#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    cin >> N;
    vector<pair<int, int>> Dot(N);
    for(int i = 0; i < N; i++){
        //second 좌표 (y)를 먼저 비교해야하므로 순서 바꾸어서 넣는다
        cin >> Dot[i].second >> Dot[i].first;
    }
    //pair의 크기 비교시 first인자의 크기 먼저 비교, 만약 같으면 second인자 비교
    sort(Dot.begin(), Dot.end()); 
    
    
    for(int i = 0; i < N; i++){
        cout << Dot[i].second << " " << Dot[i].first << "\n";
    }
    
    return 0;
}
