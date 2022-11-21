#include<stdio.h>
#define maxn 520
int exist[10][maxn];
int cal(char *s, int x){
    int mask = 0;
    for(int i = 0; i < 10; i++){
        if(i == x) continue;
        mask = (mask<<1) | (s[i]-'0');
    }
    return mask;
}
int main(void){
    int n, cnt = 0;
    scanf("%d", &n);
    char s[11];
    while(n--){
        scanf("%s", s);
        for(int i = 0; i < 10; i++){
            if(s[i] == 'x'){
                int tmp = cal(s, i);
                if(exist[i][tmp] == 0){
                    exist[i][tmp] = 1;
                    cnt++;
                }
            }
        }
    }
    printf("%d\n", cnt);
}
