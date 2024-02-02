#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    stack<int> st;  //stack
    vector<char> v; //'+''-'를 저장하기 위한 vector
    int n;
    int count = 1;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        while(count <= x){  //1부터 x값까지 push
            st.push(count);
            v.push_back('+');
            count++;
        }
        
        if(x == st.top()){  //Top의 숫자가 x값과 같으면 pop
            st.pop();
            v.push_back('-');
        }
        else{               //같지 않으면 수열 만들 수 없음 "NO"
            cout << "NO";
            return 0;       //그대로 종료
        }
    }
    
    for(int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
    
    return 0;
}
