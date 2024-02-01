#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int num[500001] = {0, };

int mean(){
    double answer = 0;
    for(int i = 0; i < n; i++){
        answer += num[i];
    }
    return round(answer / n);
}

int median(){
    return num[n / 2];
}

int mode(){
    int answer2;
    int count[8001] = {0, };
    int check = 0;
    
    for(int i = 0; i < n; i++){
        //-4000~4000 사이의 값들이 각각 몇번 나오는지 count 배열에 넣음
        count[num[i] + 4000]++;
    }
    //주소를 return 하기 때문에 * 붙여줘야함.
    int max = *max_element(count, count + 8001);
    for(int i = 0; i < 8001; i++){
        if(count[i] == max){
            check++;
            answer2 = i - 4000;
        }
        if(check == 2){
            break;
        }
    }
    return answer2;
}

int range(){
    return num[n - 1] - num[0];
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    
    sort(num, num + n); //오름차순 정리
    
    cout << mean() << '\n';
    cout << median() << '\n';
    cout << mode() << '\n';
    cout << range() << '\n';
    
    return 0;
}
