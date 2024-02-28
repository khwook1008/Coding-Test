#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N, a[9] = {0, }, ans = 0;
  cin >> N;

  while(N){
    if(N%10 == 6 || N%10 == 9){
        a[6]++;
    }
    else{
        a[N%10]++;
    }
    N /= 10;
  }
  
  a[6] = (a[6] + 1) / 2;

  for(int i = 0; i < 10; i++){
    ans = max(ans, a[i]);
  }
  cout << ans;
}