#include <stdio.h>
#include <iostream>

int main()
{
    int test, H, W, N, floor, num;
    
    scanf("%d", &test);
    for(int i = 0; i < test; i++){
        scanf("%d %d %d", &H, &W, &N);
        
        if(N % H == 0){
            floor = H;
            num = N / H;
        }
        else{
            floor = N % H;
            num = N / H + 1;
        }
        
        printf("%d%02d\n", floor, num);
    }

    return 0;
}
