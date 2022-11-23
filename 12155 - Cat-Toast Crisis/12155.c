#include<stdio.h>
int n, r, x[1005], y[1005], dist[1005][1005], used[1005], alone, total;
void dfs(int id, int first){
    used[id] = 1;
    int flag = 1;
    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        if(dist[id][i] <= r*r) {dfs(i, 0); flag = 0;}
    }
    if(first && flag) alone++;
}
int main(void){
    scanf("%d %d", &n, &r);
    for(int i = 0; i < n; i++){
        scanf("%d %d", x+i, y+i);
        for(int j = 0; j <= i; j++){
            dist[i][j] = dist[j][i] = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
        }
    }
    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        dfs(i, 1);
        total++;
    }
    printf("%d %d\n", alone, total-alone);
    return 0;
}