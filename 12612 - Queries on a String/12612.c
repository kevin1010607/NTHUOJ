#include<stdio.h>
#include<string.h>
char s[10005], tmp[10005];
int main(void){
    scanf("%s", s);
    int m, l, r, k, sub_len;
    scanf("%d", &m);
    while(m--){
        scanf("%d %d %d", &l, &r, &k);
        sub_len = r-l+1;
        k %= sub_len;
        memcpy(tmp, s+(l-1), sub_len*sizeof(char));
        for(int i = 0; i < sub_len; i++)
            s[(l-1)+(i+k)%sub_len] = tmp[i];
    }
    printf("%s\n", s);
    return 0;
}