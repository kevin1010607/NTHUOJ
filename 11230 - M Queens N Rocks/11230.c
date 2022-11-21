#include<stdio.h>
int cnt, q, r, m, n, col[10], d1[20], d2[20], d1r[20], d2r[20];
void solve(int i){
    if(i == n+m) {cnt++; return;}
    for(int j = 0; j < m+n; j++){
        if(col[j]) continue;
        if(q<m && !d1[i+j] && !d2[10+i-j] && !d1r[i+j] && !d2r[10+i-j]){
            col[j] = d1[i+j] = d2[10+i-j] = 1, q++;
            solve(i+1);
            col[j] = d1[i+j] = d2[10+i-j] = 0, q--;
        }
        if(r<n && !d1[i+j] && !d2[10+i-j]){
            col[j] = 1, r++, d1r[i+j]++, d2r[10+i-j]++;
            solve(i+1);
            col[j] = 0, r--, d1r[i+j]--, d2r[10+i-j]--;
        }
    }
}
int main(void){
    scanf("%d %d", &m, &n);
    solve(0);
    printf("%d\n", cnt);
    return 0;
}