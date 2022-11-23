#include<stdio.h>
int col[15], dia1[30], dia2[30];
int cnt, n;
void place(int row){
    if(row == n) cnt++;
    else{
        for(int i = 0; i < n; i++){
            if(col[i] || dia1[row+i] || dia2[15+row-i]) continue;
            col[i] = dia1[row+i] = dia2[15+row-i] = 1;
            place(row+1);
            col[i] = dia1[row+i] = dia2[15+row-i] = 0;
        }
    }
}
int main(void){
    scanf("%d", &n);
    place(0);
    printf("%d\n", cnt);
    return 0;
}
