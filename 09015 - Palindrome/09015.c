#include<stdio.h>
#include<string.h>
#define maxn 100005
int main(void){
    char s[maxn];
    while(scanf("%s", s) != EOF){
        int len = strlen(s);
        int ans = 1;
        for(int i = 0; i < len/2; i++){
            if(s[i] != s[len-1-i]) {
                ans = 0;
                break;
            }
        }
        if(ans) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
