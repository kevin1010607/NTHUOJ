#include<stdio.h>
int arr[25][25], on[25][25], num[10];
int n, m, idx;
int mod_2(int a){
    return (a%2);
}
void cal_on(){
    //Row 1
    on[1][0] = mod_2(on[0][0]+on[0][1]+1+arr[0][0]);
    for(int j = 1; j <= m-2; j++)
        on[1][j] = mod_2(on[0][j-1]+on[0][j]+on[0][j+1]+1+arr[0][j]);
    on[1][m-1] = mod_2(on[0][m-2]+on[0][m-1]+1+arr[0][m-1]);
    //Row 2~n
    for(int i = 2; i <= n; i++){
        on[i][0] = mod_2(on[i-1][0]+on[i-1][1]+on[i-2][0]+1+arr[i-1][0]);
        for(int j = 1; j <= m-2; j++)
            on[i][j] = mod_2(on[i-1][j-1]+on[i-1][j]+on[i-1][j+1]+on[i-2][j]+1+arr[i-1][j]);
        on[i][m-1] = mod_2(on[i-1][m-2]+on[i-1][m-1]+on[i-2][m-1]+1+arr[i-1][m-1]);
    }
}
void solve(int column){
    if(column == m){
        cal_on();
        int flag = 1;
        for(int j = 0; j < m; j++){
            if(on[n][j] == 1){
                flag = 0;
                break;
            }
        }
        if(flag){
            int ans = 0;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    ans += on[i][j];
            num[idx++] = ans;
        }
    }
    else{
        for(int i = 0; i < 2; i++){
            on[0][column] = i;
            solve(column+1);
        }
        on[0][column] = 0;
    }
}
int main(void){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);
    solve(0);
    if(idx == 0) printf("no solution\n");
    else{
        int min = num[0];
        for(int i = 1; i < idx; i++)
            if(num[i] < min) min = num[i];
        printf("%d\n", min);
    }
    return 0;
}
