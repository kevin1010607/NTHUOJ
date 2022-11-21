#include<stdio.h>
#include<stdlib.h>
int num[26];
int main(void){
    int n;
    scanf("%d", &n);
    char *s = (char*)malloc((n+1)*sizeof(char));
    scanf("%s", s);
    if(n>26 || n==1) printf("I'm the god of Knuckles!\n");
    else{
        for(int i = 0; i < n; i++)
            num[s[i]-'a']++;
        int ans = 0;
        for(int i = 0; i < 26; i++)
            if(num[i] > 1) {ans = 1; break;}
        if(ans) printf("I'm the god of Knuckles!\n");
        else printf("Different makes perfect\n");
    }
    free(s);
    return 0;
}