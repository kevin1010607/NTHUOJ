#include<stdio.h>
#include<stdlib.h>
int code[10][520], cnt;
int used[10][520];
char A[3][4], B[3][4];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
void swap(char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void solve(int x, int y, int k, int now){
    if(now > k) return;
    int pos, num = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(B[i][j] == 'x'){
                pos = 3*i+j;
                num = num<<1;
            }
            else{
                num = (num<<1)|(B[i][j]-'0');
            }
        }
    }
    //printf("%d %d %d\n", pos, num, used[pos][num]);
    if(used[pos][num] == 0){
        cnt += code[pos][num];
        used[pos][num] = 1;
    }
    for(int i = 0; i < 4; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0 || nx>=3 || ny<0 || ny>=3) continue;
        swap(&B[nx][ny], &B[x][y]);
        solve(nx, ny, k, now+1);
        swap(&B[nx][ny], &B[x][y]);
    }
}
int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int s = 0; s < n; s++){
        int pos, num = 0;
        for(int i = 0; i < 3; i++){
            scanf("%s", A[i]);
            for(int j = 0; j < 3; j++){
                if(A[i][j] == 'x'){
                    pos = 3*i+j;
                    num = num<<1;
                }
                else{
                    num = (num<<1)|(A[i][j]-'0');
                }
            }
        }
        //printf("%d %d\n", pos, num);
        code[pos][num]++;
    }
    int x, y;
    for(int i = 0; i < 3; i++){
        scanf("%s", B[i]);
        for(int j = 0; j < 3; j++)
            if(B[i][j] == 'x')
                x = i, y = j;
    }
    solve(x, y, k, 0);
    printf("%d\n", cnt);
    return 0;
}