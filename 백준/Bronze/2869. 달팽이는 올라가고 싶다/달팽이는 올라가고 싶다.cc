#include <iostream>

using namespace std;

int main()
{
    int A, B, V;
    int day = 0;
    
    cin >> A >> B >> V;
    
    if((V-B) % (A-B)){
        day = (V-B)/(A-B) + 1;
    }
    else{
        day = (V-B)/(A-B);
    }
    
    cout << day;

    return 0;
}
