#include<stdio.h>
int arr[15][15], s[15];
long long point[1000];
int n, idx, sol;
void place(int);
int valid(int, int);
long long getPoint();
int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    place(0);
    if(sol){
        long long max = point[0];
        for(int i = 1; i < idx; i++)
            if(point[i] > max)
                max = point[i];
        printf("%lld\n", max);
    }
    else
        printf("no solution\n");
    return 0;
}
void place(int row){
    if(row == n){
        point[idx++] = getPoint();
        sol = 1;
    }
    else{
        for(int i = 0; i < n; i++){
            if(valid(row, i)){
                s[row] = i;
                place(row+1);
            }
        }
    }
}
int valid(int row, int col){
    for(int i = 0; i < row; i++)
        if(i-s[i] == row-col || i+s[i] == row+col || s[i] == col)
            return 0;
    return 1;
}
long long getPoint(){
    long long point = 0;
    for(int i = 0; i < n; i++)
        point += arr[i][s[i]];
    return point;
}