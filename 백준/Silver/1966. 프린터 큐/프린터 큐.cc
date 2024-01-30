#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <queue>

using namespace std;

int main() {
	int num;
	int n, m, o;
	int count;

	cin >> num;

    for(int i = 0; i < num; i++){
        cin >> n >> m;
        
        priority_queue<int> pq; //priority_queue는 내림차순 default로 설정정
        
        queue<pair<int, int>> q;
        
        for(int j = 0; j < n; j++){
            cin >> o ;
            q.push({j, o}); //인덱스와 중요도
            pq.push(o); //중요도 priority_queue push
        }
        
        count = 0;
        
        while(!q.empty()){
            int location = q.front().first;
            int value = q.front().second;
            q.pop();
            
            if(pq.top() == value){
                pq.pop();
                count++;
                if(m == location){
                    cout << count << '\n';
                    break;
                }
            }
            else q.push({location, value});
        }
        
    }
	
    return 0;
}