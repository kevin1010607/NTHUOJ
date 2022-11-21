#include<stdio.h>
int main(void){
    int ball[5];
    for(int i = 0; i < 5; i++)
        ball[i] = i;

    int k;
    scanf("%d", &k);
    while(k--){
        int a, b;
        scanf("%d %d", &a, &b);
        int temp = ball[a];
        ball[a] = ball[b];
        ball[b] = temp;
    }
    for(int i = 0; i < 5; i++){
        if(i == 0) printf("%d", ball[i]);
        else printf(" %d", ball[i]);
    }
    return 0;
}
