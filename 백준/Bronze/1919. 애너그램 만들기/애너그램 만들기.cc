// 1919 브론즈2 애너그램 만들기
// 구현 문자열
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s1, s2;
    
    int result = 0;
    int alphabet1[26] = {};
    int alphabet2[26] = {};

    cin >> s1 >> s2;

    for(int j = 0; j < s1.length(); j++){
        alphabet1[s1[j]-'a']++;
    }
    for(int k = 0; k < s2.length(); k++){
        alphabet2[s2[k]-'a']++;
    }

    for(int i = 0; i < 26; i++){
        result += abs(alphabet1[i] - alphabet2[i]);
    }

    cout << result;
    
    return 0;
}