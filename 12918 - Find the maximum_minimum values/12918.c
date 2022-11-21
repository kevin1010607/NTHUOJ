#include<stdio.h>
#include<stdlib.h>
int main(void){
    int r, c, tmp;
    scanf("%d %d", &r, &c);
    int Mi, Mj, mi, mj;
    int M = -1, m = 999999999;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &tmp);
            if(tmp > M)
                Mi = i, Mj = j, M = tmp;
            if(tmp < m)
                mi = i, mj = j, m = tmp;
        }
    }
    printf("%d %d", abs(Mi-mi)+abs(Mj-mj), M-m);
    return 0;
}