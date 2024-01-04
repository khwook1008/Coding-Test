#include <iostream>
using namespace std;

int main(){
    int star;
    cin >> star;
    
    for(int i = 0; i < star; i++){
        for(int j = 0; j <= i; j++){
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}
