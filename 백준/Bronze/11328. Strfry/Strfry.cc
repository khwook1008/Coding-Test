// 11328 브론즈2 Strfry
// 구현 문자열
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    
    string s1, s2;

    cin >> N;
    
    for(int i = 0; i < N; i++){
        int alphabet[26] = {};
        cin >> s1 >> s2;
        
        for(int j = 0; j < s1.length(); j++){
            alphabet[s1[j]-'a']++;
        }
        for(int k = 0; k < s2.length(); k++){
            alphabet[s2[k]-'a']--;
        }

        bool isPossible = true;

        for(int i = 0; i < 26; i++){
            if(alphabet[i] != 0){
                isPossible = false;
            }
        }

        if(isPossible){
            cout << "Possible\n";
        }
        else{
            cout << "Impossible\n";
        }
    }
    return 0;
}