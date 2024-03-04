#include <iostream>
#include <list>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    stack<pair<int, int>> st; //index value
    
    int N;
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        int K;
        cin >> K;
        
        if(st.empty()){
            cout << "0 ";
            st.push({i, K});
        }
        else{
            while(!st.empty()){
                if(st.top().second > K){
                    cout << st.top().first << " ";
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(st.empty()){
                cout << "0 ";
            }
            
            st.push({i, K});
        }
    }

    return 0;
}