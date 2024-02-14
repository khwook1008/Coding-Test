#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N ;
	vector<int> dp(N + 1);

	//DP를 사용해야한다, 규칙성을 찾아야함
	dp[1] = 0; //1은 그냥 1이기 때문에 계산과정 0회
	
	//dp[4]라면 2로 나누고 2로 나누면 1 => 2회
	//dp[5]라면 1을 빼고 dp[4]과정 진행 1+2회
	//dp[6]라면 3을 나누고 2로 나누면 1 => 2회 ///dp[5] + 1하는게 최솟값이 아님
	for(int i = 2; i <= N; i++){
		
		dp[i] = dp[i - 1] + 1;
		
		if(!(i % 3)){ 
		    dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		
		if(!(i % 2)){
		    dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}

	cout << dp[N] << endl;
	return 0;
}