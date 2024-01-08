#include <stdio.h>
int main(void)
{
    int n, m;
    int sum, max = 0;
    int i, j, k;
    int arr[100] = {0};
    int count = 0;
    
    scanf("%d %d", &n, &m);
    
    sum = m;
    
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    //모든 케이스를 다 훑어보기 브루트포스(brute + force) 
    //nC3
    for (i = 0; i < n - 2; i++){ // 3장 고르기 때문에 앞에 두장 고정 후 돌리기
        for (j = i + 1; j < n - 1; j++){
            for (k = j + 1; k < n; k++){
                sum = arr[i] + arr[j] + arr[k];
                if (sum <= m && max < sum){
                    max = sum;
                }
            }
        }
    }
    printf("%d", max);
    return 0;
}