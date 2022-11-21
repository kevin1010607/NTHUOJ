#include<stdio.h>
char s[110][110];
int used[110][110];
int R, C, Si, Sj, step_min;
int solve(int i, int j, int sum, int step){
    if(s[i][j] == 'F'){
        sum += 1;
        if(step < step_min) step_min = step;
    }
    else{
        used[i][j] = 1;
        int l = 0, r = 0, u = 0, d = 0;
        if(j != 0 && s[i][j-1] != '#' && used[i][j-1] == 0)
            l = solve(i, j-1, sum, step+1);
        if(j != C-1 && s[i][j+1] != '#' && used[i][j+1] == 0)
            r = solve(i, j+1, sum, step+1);
        if(i != 0 && s[i-1][j] != '#' && used[i-1][j] == 0)
            u = solve(i-1, j, sum, step+1);
        if(i != R-1 && s[i+1][j] != '#' && used[i+1][j] == 0)
            d = solve(i+1, j, sum, step+1);
        used[i][j] = 0;
        sum = l+r+u+d;
    }
    return sum;
}
int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &R, &C);
        for(int i = 0; i < R; i++){
            scanf("%s", s[i]);
            for(int j = 0; j < C; j++){
                if(s[i][j] == 'S'){
                    Si = i;
                    Sj = j;
                }
            }
        }
        step_min = 1000000;
        int sol = solve(Si, Sj, 0, 0);
        if(sol == 0) printf("%d %d\n", sol, -1);
        else printf("%d %d\n", sol, step_min);
    }
    return 0;
}