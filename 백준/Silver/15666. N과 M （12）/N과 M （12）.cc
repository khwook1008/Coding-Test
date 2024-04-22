// 15666 실버2 N과 M (12)
// N개의 자연수와 자연수 M, N개의 자연수 중에서 M개를 고른 수열, 
// 수열들은 사전순으로 증가하는 순서로 출력, 같은 수를 여러번 골라도 된다
// 비내림차순
// 3 1    
// 4 4 2  주어지는 자연수가 중복되는 것으로 바뀜
// 백트래킹, 재귀

#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];		// 수열을 담을 배열
int example[10];  	// 주어진 자연수 배열
//bool isused[10]; 	// 특정 수가 쓰였는지 확인하는 배열

void func(int k, int start)
{
	if(k == m){
		for(int i = 0; i < m; i++){
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	// int start = 0;
	// if(k != 0){
	// 	start = arr[k - 1]; 
	// }
	int tmp = 0; // 수열이 중복인지 체크

	for(int i = start; i < n; i++){
		// 이 전 수열의 마지막항과 새로운 수열의 마지막항이 같으면 중복 수열
		//if(isused[i] != 1 && tmp != example[i]){
		if(tmp != example[i]){
			//isused[i] = 1;
			arr[k] = example[i];
			tmp = arr[k];
			func(k+1, i);
			//isused[i] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> example[i];
	}
	sort(example, example + n); //오름차순 정렬
	func(0, 0);
}