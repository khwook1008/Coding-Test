#include <stdio.h>

int main()
{
    int N, Num;
    int check = 0;
    int total = 0;
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        scanf("%d" , &Num);
        for(int j = 1; j < Num; j++){
            if(Num % j == 0){
                check++;
            }
        }
        if(check == 1){
            total++;
        }
        check  = 0;
    }
    printf("%d", total);
    return 0;
}