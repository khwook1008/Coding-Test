#include <iostream>
#include <algorithm>
#include <utility>
#include<cmath>

using namespace std;

int main() {
	int n;
	float total;
	cin >> n;

	if (n == 0) {
		cout << 0; 
		return 0;
	}
	
	int arr[n];
	
	for(int i = 0; i < n; i++){
	    cin >> arr[i];
	}
	
	sort(arr, arr+n);
	
	int first = round(n*0.15);
	int last = n-round(n*0.15);
	
	for(int i = first; i < last; i++){
	    total += arr[i];
	}
	
	cout << round(total / (n-first*2));
	
    return 0;
}