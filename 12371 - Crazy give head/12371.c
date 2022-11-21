#include<stdio.h>
#include<string.h>
char S[1005], p[1005];
int prefix[1005];
int main(void){
    while(~scanf("%s %s", S+1, p)){
        int lenS = strlen(S+1);
        int lenp = strlen(p);
        for(int i = 1; i <= lenS; i++){
            if(i < lenp) {prefix[i] = 0; continue;}
            prefix[i] = prefix[i-1];
            if(!strncmp(S+1+i-lenp, p, lenp)) prefix[i]++;
        }
        int q, a, b, max = -1;
        scanf("%d", &q);
        while(q--){
            scanf("%d %d", &a, &b);
            int ans;
            if(b-a+1 < lenp) ans = 0;
            else ans = prefix[b]-prefix[a+lenp-2];
            if(ans > max) max = ans;
        }
        printf("%d\n", max);
    }
    return 0;
}