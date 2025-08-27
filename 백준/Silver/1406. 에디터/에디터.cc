// 1406 실버2 에디터

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    list<char> L;
    for(auto c : str){
        L.push_back(c);
    }
    auto cursor = L.end();

    int M;
    cin >> M;
    while(M--){
        char cmd;
        cin >> cmd;
        
        if(cmd == 'L'){
            if(cursor != L.begin()){
                cursor--;
            }
        }
        else if(cmd == 'D'){
            if(cursor != L.end()){
                cursor++;
            }
        }
        else if(cmd == 'B'){
            if(cursor != L.begin()){
                cursor--;
                cursor = L.erase(cursor);
            }
        }
        else if(cmd == 'P'){
            char a;
            cin >> a;
            L.insert(cursor, a);
        }
    }
    for(auto c : L){
        cout << c;
    }

    return 0;
}