#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int n;
	while(true){
	    cin>>n;
	    if(n==0){
	        break;
	    }
	    else{
	        int left=1,right=50;
	        while(left<=right){         //종료 방식 확인
	            int mid=(left+right)/2;
	            if(n==mid){
	                cout<<mid<<"\n";
	                left=right+1;       //종료 조건 만들기
	            }
	            else if(n>mid){
	                cout<<mid<<" ";
	                left=mid+1;
	            }
	            else{
	                cout<<mid<<" ";
	                right=mid-1;
	            }
	        }
	    }
	}
	return 0;
}