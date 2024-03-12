#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        
        string str;
        
        getline(cin, str); //한줄을 한꺼번에 다 입력 받아야한다.
        
        if(str == "."){ //'.' string이 한글자 들어오면 종료
            break;
        }
        
        stack<char> st;
        int no = 0;
        
        for(int i = 0; i < str.length(); i++){
            char c = str[i];
            if(c == '(' || c == '['){
                st.push(c);
            }
            else if(c == ')'){
                if(st.empty() || st.top() != '('){
                    no = 1;
                    break;
                }
                else{
                    st.pop();
                }
            }
            else if(c == ']'){
                if(st.empty() || st.top() != '['){
                    no = 1;
                    break;
                }
                else{
                    st.pop();
                }
            }
        }
        if(!st.empty()){
            no = 1;
        }
        if(no == 0){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
    return 0;
}