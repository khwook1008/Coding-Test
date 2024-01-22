#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	
	int N, X;
	string command;
	stack<int> st;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
	    cin >> command;
	    
	    if(command == "push"){
	        cin >> X;
	        st.push(X);
	    }
	    else if(command == "pop"){
	        if(st.empty()){
	            cout << "-1" << "\n";
	            continue;
	        }
	        cout << st.top() << "\n";
	        st.pop();
	    }
	    else if(command == "size"){
	        cout << st.size() << "\n";
	    }
	    else if(command == "empty"){
	        if(st.empty()){
	            cout << "1" << "\n";
	        }
	        else{
	            cout << "0" << "\n";
	        }
	        
	    }
	    else if(command == "top"){
	        if(st.empty()){
	            cout << "-1" << "\n";
	            continue;
	        }
	        cout << st.top() << "\n";
	    }
	}
}
