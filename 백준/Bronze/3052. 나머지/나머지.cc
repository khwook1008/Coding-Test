#include <stdio.h>

int main(void) {
    int input;
    int result = 0;
    int remain[10];
    
    for(int i=0; i<10; i++) {
        scanf("%d", &input);
        remain[i] = (input % 42);
    }
    
    for(int i = 0; i < 10; i++){
        int cnt = 0;
        for(int j = 0; j < i; j++){
            if(remain[i] == remain[j]){
                cnt++;
            }
        }
        if(cnt == 0){
            result++;
        }
    }
   printf("%d", result);
}