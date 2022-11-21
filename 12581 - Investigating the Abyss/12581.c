#include<stdio.h>
#include<stdlib.h>
#define maxn 100005
int from[maxn], to[maxn], num[maxn], dp[maxn], idx[maxn];
int *next[maxn];
void dfs(int now){
    for(int i = 0; i < num[now]; i++){
        dfs(next[now][i]);
        dp[now] += (dp[next[now][i]]+1);
    }
}
int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d %d", &from[i], &to[i]);
        num[from[i]]++;
    }
    for(int i = 1; i <= n; i++)
        next[i] = (int*)malloc(num[i]*sizeof(int));
    for(int i = 0; i < n-1; i++)
        next[from[i]][idx[from[i]]++] = to[i];
    dfs(1);
    for(int i = 1; i < n; i++){
        printf("%d ", dp[i]);
        free(next[i]);
    }
    printf("%d\n", dp[n]);
    free(next[n]);
    return 0;
}