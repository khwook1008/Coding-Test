#include <stdio.h>
#include <string.h>

int main()
{
    int a[8];
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        scanf("%d", &a[i]);
    }
    
    if(a[0] == 1){
        for(int i = 0; i < 8; i++){
            if(a[i] == i+1){
                cnt++;
            }           
        }
        if(cnt == 8){
            printf("ascending");
            cnt = 0;
        }
        else{
            printf("mixed");
        }
    }
    else if(a[0] == 8){
        for(int i = 0; i < 8; i++){
            if(a[i] == 8-i){
                cnt++;
            }
        }
        
        if(cnt == 8){
            printf("descending");
            cnt = 0;
        }
        else{
            printf("mixed");
        }
    }
    else{
        printf("mixed");
    }
    

    return 0;
}
