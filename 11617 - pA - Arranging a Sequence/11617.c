#include<stdio.h>
int used[200005];
int arr[100005];
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = m-1; i >= 0; i--){
        scanf("%d", &arr[i]);
        used[arr[i]] = 1;
    }
    for(int i = 0; i < m; i++){
        if(used[arr[i]] > 1) continue;
        printf("%d\n", arr[i]);
        used[arr[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(used[i]) continue;
        printf("%d\n", i);
    }
    return 0;
}
