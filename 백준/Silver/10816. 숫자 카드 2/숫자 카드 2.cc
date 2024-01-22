#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int arr[500002];
int N, M, card;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> card;
		arr[i] = card;
	}
	
	sort(arr, arr + N); // 이분탐색해야하니 오름차순 정렬

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> card;
		//upper_bound, card 초과의 값이 언제 처음으로 나오는지
		//lower_bound, card 이하의 값이 언제 처음으로 나오는가
		cout << upper_bound(arr, arr + N, card) - lower_bound(arr, arr + N, card)<<" ";
	}
}
