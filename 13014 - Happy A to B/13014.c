#include<stdio.h>
char A[3][4], B[3][4];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
void swap(char *a, char*b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
int solve(int x, int y, int k, int cnt){
    int same = 1;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(A[i][j] != B[i][j]) same = 0;
    if(same) return 1;
    if(cnt == k) return 0;
    for(int i = 0; i < 4; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(0 <= nx && nx <= 3 && 0 <= ny && ny <= 3){
            swap(&A[x][y], &A[nx][ny]);
            if(solve(nx, ny, k, cnt+1)) return 1;
            swap(&A[x][y], &A[nx][ny]);
        }
    }
    return 0;
}
int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int k, x, y;
        scanf("%d", &k);
        for(int i = 0; i < 3; i++) scanf("%s", A[i]);
        for(int i = 0; i < 3; i++) scanf("%s", B[i]);
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(A[i][j] == 'x') x = i, y = j;
        printf("%s\n", (solve(x, y, k, 0)?"Yes":"No"));
    }
}