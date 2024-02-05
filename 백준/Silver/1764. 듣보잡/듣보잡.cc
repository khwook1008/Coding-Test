#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
    
    int n, m;
    int cnt = 0;
    
    string str;
    vector<string> result;
    map<string, bool> list;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str;
        //해시맵에 듣도 못한 사람 넣기
        list.insert(make_pair(str, true));
    }
    
    for(int i = 0; i < m; i++){
        cin >> str;
        if(list[str]){ //똑같은 이름 있으면 (true)
            result.push_back(str); //이름 출력해야하니 기록
            cnt++; //듣보잡 ++
        }
    }
    //사전 순, 오름차순으로 정렬
    sort(result.begin(), result.end());
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++){
        cout << result[i] << endl;
    }
    
	return 0;
}