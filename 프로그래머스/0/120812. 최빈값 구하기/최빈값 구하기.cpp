#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> array) {
    int count [1001] = {0};
    for(int num : array){
        count[num]++;
    }
    
    int maxCount = 0;
    int answer = 0;
    
    for(int i = 0; i <= 1000; i++){
        if(count[i] > maxCount){
            maxCount = count[i];
            answer = i;
        }
    }
    cout << "mc : " << maxCount << endl;
    cout << "ans : "<< answer << endl;
    
    int sameCount = 0;
    for(int i = 0; i<= 1000; i++){
        if(count[i] == maxCount){
            sameCount++;
            if(sameCount > 1){
                return -1;
            }
        }
    }
    return answer;
}