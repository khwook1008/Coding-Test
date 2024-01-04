#include <stdio.h>
#include <string.h>

int main(){
    char s[1000001];
    scanf("%[^\n]s", s);
    
    int cnt = 0;
    
    if(s[0] != ' '){
        cnt++;
    }
    
    for(int i = 1; i < strlen(s); i++){
        if(s[i-1] == ' ' && s[i] != ' '){
            cnt++;
        }
    }
    
    printf("%d", cnt);
    
    return 0;
}