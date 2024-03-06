#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N, M;
	int ans = 0;
	cin >> N >> M;
	
	deque<int> dq;
	for(int i = 1; i <= N; i++){
	    dq.push_back(i);
	}
	
	while(M--){
	    int t;
	    cin >> t;
	    int idx = find(dq.begin(), dq.end(), t) - dq.begin(); // t의 위치
	    
	    while(dq.front() != t){
	        if(idx  < dq.size() - idx){
	            dq.push_back(dq.front());
	            dq.pop_front();
	        }
	        else{
	            dq.push_front(dq.back());
	            dq.pop_back();
	        }
	        ans++;
	    }
	    dq.pop_front();
	}
	cout << ans;
	return 0;
}
