#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main() {

    int N;
	int ans = 0;
	cin >> N;

	for (int i = 5; i <= N; i *= 5) {
		ans += N / i;
	}
	cout << ans;

	return 0;
}
