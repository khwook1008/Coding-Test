#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000001];
    char answer;
    int arr[26];
    int max = 0;
    int len;
    
    scanf("%s", s);
    len = strlen(s);
    
    for(int i = 0; i < len; i++){ //strlen for문 안에 돌리면 시간초과 발생
        if(s[i] >= 'a'){
            arr[s[i] - 'a']++;
        }
        else{
            arr[s[i] - 'A']++;
        }
    }
    
    for(int i = 0; i < 26; i++){
        if(max == arr[i]){
            answer = '?';
        }
        else if(max < arr[i]){
            max = arr[i];
            answer = 'A' + i;
        }
    }
    printf("%c", answer);

    return 0;
}
