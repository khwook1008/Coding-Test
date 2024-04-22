// 15657 실버3 N과 M (8)
// N개의 자연수와 자연수 M, N개의 자연수 중에서 M개를 고른 수열, 
// 수열들은 사전순으로 증가하는 순서로 출력, 수열은 비내림차순 이어야한다.
// 백트래킹, 재귀

#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];		// 수열을 담을 배열
int example[10];  	// 주어진 자연수 배열
//bool isused[10]; 	// 특정 수가 쓰였는지 확인하는 배열

void func(int k)
{
	if(k == m){
		for(int i = 0; i < m; i++){
			cout << example[arr[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	int start = 0;
	if(k != 0){
		start = arr[k - 1]; 
	}
	for(int i = start; i < n; i++){
		//if(isused[i] != 1){
		//	isused[i] = 1;
			arr[k] = i;
			func(k+1);
		//	isused[i] = 0;
		//}
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
	func(0);
}