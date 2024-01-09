#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    
    int N;
    cin >> N;
    
    double arr[1001];
    double sum = 0;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    for(int i = 0; i < N; i++){
        arr[i] = arr[i] / arr[N - 1] * 100;
        sum += arr[i];
    }
    
    cout << sum / N;
    
    return 0;
}
