#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int N;
    
    cin >> N;
    
    while(N--){ //Case 하나씩 쳐내면서
        stack<char> st; //Stack으로  처리, 짝이 맞아야만 Pop 할 수 있다.
        string s;
        
        cin >> s;
        
        for(int i = 0; i < s.length(); i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(st.top() == '(' && s[i] == ')'){ //짝 맞추기 (최근 남은거랑 지금 들어온거)
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        
        if(st.empty()){
            cout << "YES" << "\n"; //짝이 다 맞아서 Pop을 다 해버리면 성공
        }
        else{
            cout << "NO" << "\n"; // 남아있으면 실패
        }
        
    }

    return 0;
}
