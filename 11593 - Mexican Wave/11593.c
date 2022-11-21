#include<stdio.h>
#define maxn 105
int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m, t;
        scanf("%d %d %d", &n, &m, &t);
        char spe[maxn] = {};
        for(int i = 0; i < n; i++)
            spe[i] = '-';
        for(int i = 0; i < t; i++){
            if(i < m) spe[i] = '^';
            else if(i >= m && i < n+m)
                spe[i] = '^', spe[i-m] = '-';
            else break;
        }
        for(int i = 0; i < n; i++)
            putchar(spe[i]);
        printf("\n");
    }

    return 0;
}