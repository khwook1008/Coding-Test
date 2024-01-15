#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int N, K;

	cin >> N >> K;
	
	queue<int> josephus; //queue를 사용용
	
	for (int i = 1; i <= N; i++) {
		josephus.push(i);           //queue에 순서대로 넣어준다
	}

	cout << "<";
	
	while(1){
	    //K번째 원소가 queue의 가장 앞에 오도록 한다
	    //나갈 원소 앞에 있던 원소들은 queue의 뒤에 삽입
	    for(int i = 0; i < K - 1; i++){
	        int tmp = josephus.front();
	        josephus.push(tmp);
	        josephus.pop();
	    }
	    //for문 끝나고 현재 K번째 원소가 제일 앞에 온 상태
	    
	    cout << josephus.front(); //제일 앞 원소 출력
	    josephus.pop(); //출력 후 삭제
	    
	    if(josephus.empty()){ //큐가 비어있으면 .empty()는 1을 반환
	        break;
	    }
	    else{
	        cout << ", ";
	    }
	}
	
	cout << ">";
	
	return 0;
}