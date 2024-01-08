#include <stdio.h>
#include <string.h>

int main()
{
    int a, b, c, d;
    int arr[10] = {0, };
    scanf("%d %d %d", &a, &b, &c);
    
    d = a * b * c;
    
    for(int i = d; i > 0; i/=10){
       arr[i%10]++;
    }
    
    for(int i = 0; i < 10; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}
