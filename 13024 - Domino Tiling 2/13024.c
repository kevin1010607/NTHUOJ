#include<stdio.h>
#include<stdbool.h>
bool used[55][55];
int n, m;
long long sol;
void solve(int idx){
    int i = idx/m, j = idx%m;
    if(idx == n*m-1) sol++;
    else{
        if(used[i][j]) solve(idx+1);
        else{
            used[i][j] = true;
            if(j != m-1 && !used[i][j+1]){
                used[i][j+1] = true;
                solve(idx+1);
                used[i][j+1] = false;
            }
            if(i != n-1 && !used[i+1][j]){
                used[i+1][j] = true;
                solve(idx+1);
                used[i+1][j] = false;
            }
            used[i][j] = false;
        }
    }
}
int main(void){
    scanf("%d %d", &n, &m);
    solve(0);
    printf("%lld\n", sol);
    return 0;
}