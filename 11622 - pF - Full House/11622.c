#include<stdio.h>
int card[13], num[13];
int get(char c){
    if(c == 'A') return 1;
    if(c == '1') return 10;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    if(c == 'K') return 13;
    return c-'0';
}
int main(void){
    int t;
    scanf("%d", &t);
    getchar();
    while(t--){
        int s, idx = 0;
        for(int i = 0; i < 5; i++){
            s = get(getchar());
            int newCard = 1;
            for(int j = 0; j < idx; j++)
                if(s == card[j]){num[j]++, newCard = 0;}
            if(newCard){
                card[idx] = s;
                num[idx] = 1;
                idx++;
            }
            if(s == 10) getchar();
            getchar();
        }
        if(idx==2 && ((num[0]==2&&num[1]==3)||(num[0]==3&&num[1]==2)))
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
