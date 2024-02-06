#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    while(1){
	    int n, m, num;
	    int it1 = 0;
	    int it2 = 0;
	    int cnt = 0;
	
    	cin >> n >> m;
    	vector<int> vec1;
    	vector<int> vec2;
    
    	if(n == 0 && m == 0){
    	    break;
    	}
    	
    	for (int i = 0; i < n; i++) {
			cin >> num;
			vec1.push_back(num);
		}
		for (int i = 0; i < m; i++) {
			cin >> num;
			vec2.push_back(num);
		}
		
		while(1){
		    //index중 하나의 사이즈만 넘어가도 종료
		    if(it1 == vec1.size() || it2 == vec2.size()){
		        break;
		    }
		    //똑같으면 갯수 증가 후 둘다 iterator 증가
		    if(vec1[it1] == vec2[it2]){
		        cnt++;
		        it1++;
		        it2++;
		    }
		    //입력이 오름차순으로 들어오고 있기 때문에 비교해서 작은 부분만 iterator 증가
		    else if(vec1[it1] > vec2[it2]){
		        it2++;
		    }
		    else{
		        it1++;
		    }
		}
		cout << cnt << '\n';
    }
    return 0;
}