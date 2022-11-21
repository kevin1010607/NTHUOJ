#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[500005];
int main(void){
    fgets(s, sizeof(s), stdin);
    int idx = 0, cnt = 0;
    char c;
    while((c = getchar()) != EOF){
        if(isalpha(c) || c == ' '){
            if(c == s[idx] && cnt == 0){
                idx++;
                printf("1\n");
            }
            else{
                cnt++;
                printf("0\n");
            }
        }
        else{
            if(cnt == 0){
                if(idx != 0) idx--;
                printf("1\n");
            }
            else{
                printf("%d\n", (cnt == 1?1:0));
                cnt--;
            }
            getchar();
        }
        getchar();
    }
    if(strlen(s) == idx+1 && cnt == 0) printf("Correct\n");
    else printf("Incorrect\n");
    return 0;
}