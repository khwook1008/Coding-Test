#include <stdio.h>
int main() 
{
    int array[9];
    int max = 0;
    int index;
    
    for(int i = 0; i < 9; i++)
    {
        scanf("%d", &array[i]);
        if(max < array[i])
        {
            max = array[i];
            index = i;
        }
       
    }
    printf("%d\n%d", max, index + 1);
    
    return 0;
}