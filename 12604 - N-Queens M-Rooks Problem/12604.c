#include<stdio.h>
#include<stdbool.h>
int n, m, cnt;
bool used_col[10];
bool used_dia1_Q[30], used_dia2_Q[30];
bool used_dia1_R[30], used_dia2_R[30];
int numQ, numR;
bool used[100][100];
int table[100][100];
void place(int row){
    if(row > n+m){
        cnt++;
    }
    else{
        for(int j = 1; j <= n+m; j++){
            if(used_col[j]) continue;
            if(numQ<n&&!used_dia1_Q[row+j]&&!used_dia2_Q[10+row-j]&&!used_dia1_R[row+j]&&!used_dia2_R[10+row-j]){
                numQ++;
                used_col[j] = used_dia1_Q[row+j] = used_dia2_Q[10+row-j] = true;
                place(row+1);
                used_col[j] = used_dia1_Q[row+j] = used_dia2_Q[10+row-j] = false;
                numQ--;
            }
            if(numR<m&&!used_dia1_Q[row+j]&&!used_dia2_Q[10+row-j]){
                bool flag1 = true, flag2 = true;
                if(used_dia1_R[row+j] == true) flag1 = false;
                if(used_dia2_R[10+row-j] == true) flag2 = false;
                numR++;
                used_col[j] = true;
                if(flag1) used_dia1_R[row+j] = true;
                if(flag2) used_dia2_R[10+row-j] = true;
                place(row+1);
                if(flag2) used_dia2_R[10+row-j] = false;
                if(flag1) used_dia1_R[row+j] = false;
                used_col[j] = false;
                numR--;
            }
        }
    }
}
int main(void){
    while(scanf("%d %d", &n, &m) != EOF){
        if(!used[n][m]){
            cnt = 0;
            place(1);
            table[n][m] = cnt;
            used[n][m] = true;
        }
        printf("%d\n", table[n][m]);
    }
    return 0;
}