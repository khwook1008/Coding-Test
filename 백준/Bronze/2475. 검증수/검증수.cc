#include <stdio.h>

int main(){
    int num;
    int verify = 0;
    for(int i = 0; i < 5; i++){
        scanf("%d", &num);
        verify += num * num;
    }
    verify %= 10;
    printf("%d", verify);
    return 0;
}