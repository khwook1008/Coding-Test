#include <stdio.h>

int main() {
    char s[1001];
    int num;
	scanf("%s", s);
	scanf("%d", &num);
	
	printf("%c", s[num-1]);
	
	return 0;
}