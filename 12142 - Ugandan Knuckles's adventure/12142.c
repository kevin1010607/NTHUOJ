#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{char s[1005];}node;
node S[105];
int cmp(const void *a, const void *b){
    const node *sa = (const node*)a;
    const node *sb = (const node*)b;
    char s1[2005], s2[2005];
    strcpy(s1, sa->s), strcat(s1, sb->s);
    strcpy(s2, sb->s), strcat(s2, sa->s);
    return strcmp(s1, s2) < 0;
}
int main(void){
    int n;
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i++) scanf("%s", S[i].s);
        qsort(S, n, sizeof(node), cmp);
        for(int i = 0; i < n; i++) printf("%s", S[i].s);
        puts("");
    }
    return 0;
}