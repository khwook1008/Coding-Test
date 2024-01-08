#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n-i; j++){
    //         printf(" ");
    //     }
    //     for(int k = 1; k <= i; k++){
    //         printf("*");    
    //     }
    //     printf("\n");
    // }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j <= n-i)
                printf(" ");
            else
                printf("*");    
        }
        printf("\n");
    }
	return 0;
}