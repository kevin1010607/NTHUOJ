#include<stdio.h>
int arr[10], used[10];
void permute(int, int);
int main(void){
    int n;
    scanf("%d", &n);
    permute(1, n);
    return 0;
}
void permute(int now, int n){
    if(now > n){
        for(int i = 1; i <= n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else{
        for(int i = 1; i <= n; i++){
            if(used[i])
            continue;
            arr[now] = i;
            used[i] = 1;
            permute(now+1, n);
            used[i] = 0;
        }
    }
}
