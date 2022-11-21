#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(void){
    char s[1000];
    scanf("%s", s);
    int len = strlen(s);
    int flag = 0;
    for(int i = 0; i < len; i++)
        if(s[i] == '(' && s[i-1] == '-') {flag = 1;}
        else if(s[i] == ')') {flag = 0;}
        else if(flag && s[i] == '+') {s[i] = '-';}
        else if(flag && s[i] == '-') {s[i] = '+';}

    long long ans = 0;
    int coe = 1;
    for(int i = 0; i < len; i++)
        if(s[i] == '+') {coe = 1;}
        else if(s[i] == '-') {coe = -1;}
        else if(isdigit(s[i])){
            int val = s[i]-'0';
            while(isdigit(s[++i]))
                val = 10*val+s[i]-'0';
            ans += (coe*val);
            i--;
        }
    printf("%lld\n", ans);

    return 0;
}