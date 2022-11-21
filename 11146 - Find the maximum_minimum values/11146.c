#include<stdio.h>
#include<stdlib.h>
int main(void){
    int r, c;
    scanf("%d %d", &r, &c);
    int Mi, Mj, mi, mj;
    int Mr = -1, mr = 99999999;
    for(int i = 0, val; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &val);
            if(val > Mr){
                Mi = i;
                Mj = j;
                Mr = val;
            }
            if(val < mr){
                mi = i;
                mj = j;
                mr = val;
            }
        }
    }
    printf("%d %d", abs(Mi-mi)+abs(Mj-mj), Mr-mr);
    return 0;
}
