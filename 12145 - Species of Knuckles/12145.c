#include<stdio.h>
#include<stdlib.h>
int n, ans, cnt[26];
int main(void){
    scanf("%d", &n);
    char *s = (char*)malloc((n+1)*sizeof(char));
    scanf("%s", s);
    if(n>26 || n==1) ans = 1;
    else{
        for(int i = 0; i < n; i++) cnt[s[i]-'a']++;
        for(int i = 0; i < 26; i++) if(cnt[i] > 1) ans = 1;
    }
    printf("%s\n", ans?"I'm the god of Knuckles!":"Different makes perfect");
    free(s);
    return 0;
}