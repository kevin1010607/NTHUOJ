#include<stdio.h>
char s[200005];
int finally[26], tmp[26];
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    getchar();
    for(int i = 0; i < 26; i++)
        finally[i] = i;
    for(int i = 0; i < m; i++){
        char c1, c2;
        scanf("%c %c", &c1, &c2);
        getchar();
        if(c1 != c2){
            for(int i = 0; i < 26; i++){
                tmp[i] = finally[i];
                if(tmp[i] == c1-'a') finally[i] = c2-'a';
                if(tmp[i] == c2-'a') finally[i] = c1-'a';
            }
        }
    }
    for(int i = 0; i < n; i++)
        printf("%c", finally[s[i]-'a']+'a');
    printf("\n");
    return 0;
}