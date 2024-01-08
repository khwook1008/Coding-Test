#include <stdio.h>
#include <string.h>

int main()
{
    char s[101];
    char answer;
    int arr[26] = {0, };
    int max = 0;
    int len;
    
    scanf("%s", s);
    len = strlen(s);
    
    for(int i = 0; i < len; i++){ //strlen for문 안에 돌리면 시간초과 발생
        if(arr[s[i] - 'a'] == 0){
            arr[s[i] - 'a'] = i + 1;
        }
    }
    
    for(int i = 0; i < 26; i++){
        if(arr[i] == 0){
            printf("-1 ");
        }
        else{
            printf("%d ", arr[i] - 1);
        }
    }

    return 0;
}
