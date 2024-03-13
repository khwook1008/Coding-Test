#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int answer = 0;
    
    stack<char> st;
    
    cin >> str;
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            st.push(str[i]);
        }
        else{
            //레이저일때, 직전에 쌓은거는 레이저가 되었으니 pop하고 그 전까지 쌓은 나무 갯수를 더해줌줌
            if(str[i - 1] == '('){
                st.pop();
                answer += st.size();
            }
            //막대의 끝이 만들어질때, 막대가 만들어지는 pop을 하고 그 하나의 갯수를 추가가
            else{
                st.pop();
                answer++;
            }
        }
    }
    cout << answer << '\n';

    return 0;
}