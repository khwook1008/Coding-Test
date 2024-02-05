#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
    int arr[21] = {0, };
    string str;
    int x;
    
    int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
	    cin >> str;
	    
	    if(str=="add"){
            cin >> x;
            if(arr[x]==0){   //없으면
                arr[x] = 1;
            }
        }
        
        else if(str=="remove"){
            cin >> x;
            if(arr[x] == 1){  //있으면
                arr[x] = 0;
            }
            
        }
        else if(str=="check"){
            cin >> x;
            if(arr[x] == 0){   //없으면
                cout << "0\n";
            } else{
                cout << "1\n";
            }
        }
        else if(str=="toggle"){
           cin >> x;
            if(arr[x] == 1){  //있으면
                arr[x] = 0;
            } else{
                arr[x] = 1;
            }
        }
        else if(str=="all"){
            for(int k = 1; k <= 20; k++){
                arr[k] = 1;
            }
        }
        else if(str=="empty"){
            memset(arr, 0, sizeof(arr));
        }
    }
	
	return 0;
}