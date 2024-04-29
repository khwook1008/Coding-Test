//111652 카드
//정렬, 구현
//오름차순으로 정렬 후 처음부터 숫자를 확인해서 같은 수가 나오지 않을 때까지 cnt를 증가
//다른 수가 나오면 max_cnt와 cnt를 비교해서 max_cnt < cnt면 cnt를 max_cnt에 저장하고, max_val에 그 수를 저장
//가장 많이 가지고 있는 정수가 여러 가지라면, 작은 것을 출력한다.
#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[100001];
int cnt = 1, max_cnt = 1;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}


	sort(arr, arr + N); //오름차순으로 정렬 후 작은 수부터 개수를 체크하자

	long long max_num = arr[0];

	for(int i = 1; i < N; i++){
		if(arr[i] == arr[i - 1]){
			cnt++;
		}
		else{
			cnt = 1;
		}
		if(max_cnt < cnt){
			max_cnt = cnt;
			max_num = arr[i];
		}
	}
	cout << max_num;
}