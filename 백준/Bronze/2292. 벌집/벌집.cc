#include <stdio.h>

int main()
{
    int N;
    
    scanf("%d", &N);
    
    int room = 1;
    int max = 1;
    int add = 6;
    
    while(1){
        if(N <= max){
            break;
        }
        
        max += add;
        add += 6;
        room++;
    }
    
    printf("%d", room);
    return 0;
}