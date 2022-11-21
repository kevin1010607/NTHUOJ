#include<stdio.h>
int main(void){
    int x[4];
    scanf("%d %d %d %d", &x[0], &x[1], &x[2], &x[3]);
    int sa = 0, ra = 0;
    for(int i = 0; i < 4; i++){
        if(x[i]%2 == 0 && x[i] > 0) sa++;
        else if(x[i]%2 == 0 && x[i] < 0) ra++;
    }
    if(sa > ra) printf("Sammy\n");
    else if(sa+1 == ra || sa == ra) printf("Tie\n");
    else if(sa < ra+1) printf("Rachel\n");
    return 0;
}
