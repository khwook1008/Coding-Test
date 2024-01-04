#include <iostream>

using namespace std;

int main(){
    double a, b;
    cin >> a >> b;
    
    cout.precision(10);
    cout << fixed;
    cout << a / b;
    return 0;
}