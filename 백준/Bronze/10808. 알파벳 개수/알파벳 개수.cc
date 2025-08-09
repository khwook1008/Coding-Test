// 10808 브론즈4 알파벳 개수
// 구현 문자열
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string S; 
    int alphabet[26] = {0, };

    cin >> S;
    for(int i = 0; i < S.length(); i++){
        alphabet[S[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++)
	{
		cout << alphabet[i] << ' ';
	}
    
    return 0;
}