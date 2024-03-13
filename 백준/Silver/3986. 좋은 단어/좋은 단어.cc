
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    int answer = 0;
    string str;
    
    cin >> N;
    
    while(N--){
        stack<char> st;
        cin >> str;
        for(int i = 0; i < str.length(); i++){
            if(st.empty()){
                st.push(str[i]);
            }
            else if(!st.empty() && st.top() == str[i]){
                st.pop();
            }
            else{
                st.push(str[i]);
            }
        }
        if(st.empty()){
            answer++;
        }
    }
    cout << answer;

    return 0;
}
