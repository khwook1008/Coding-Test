// 6603 실버2 로또
// 독일 로또는 {1, 2, ..., 49}에서 수 6개
// 49 가지 수 중 k(k > 6)를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택
// 중복 선택 불가, 원소 자체 오름차순으로 주어짐, 사전 순 출력
// 백트래킹, 재귀

#include <bits/stdc++.h>
using namespace std;

int k;
int arr[10]; //선택하여 수열로 만들기
int input[15]; //입력 받는 수

void func(int cnt, int cur)
{
	if(cnt == 6){
		for(int i = 0; i < 6; i++){
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	//중복으로 선택 불가 cur + 1
	for(int i = cur; i < k; i++){
		arr[cnt] = input [i];
		func(cnt + 1, i + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		cin >> k;
		if (k == 0){
			break;
		}
		for(int i = 0; i < k; i++){
			cin >> input[i];
		}
		func(0, 0);
		cout << '\n';
	}
}