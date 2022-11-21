#include<stdio.h>
#include<string.h>
#define maxn 105
int main(void){
    char n[maxn] = {};
    char ans[maxn] = {};
    scanf("%s", n);
    int len = strlen(n);

    for(int i = 0; i < len; i++){
        switch(n[i]){
            case '0':
                ans[len-(i+1)] = '0';
                break;
            case '1':
                ans[len-(i+1)] = '1';
                break;
            case '6':
                ans[len-(i+1)] = '9';
                break;
            case '8':
                ans[len-(i+1)] = '8';
                break;
            case '9':
                ans[len-(i+1)] = '6';
                break;
            default:
                printf("No\n");
                return 0;
        }
    }
    int start = 0;
    while(ans[start] == '0') start++;
    ans[len] = '\0';
    printf("%s\n", ans+start);
    return 0;
}