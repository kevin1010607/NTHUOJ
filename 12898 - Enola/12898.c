#include<stdio.h>
#include<string.h>
#define maxn 1005
int main(void){
    int n, m;
    int cnt1[26], cnt2[26];
    char s1[maxn], s2[maxn];
    while(scanf("%d %d", &n, &m) != EOF){
        scanf("%s %s", s1, s2);
        if(n != m){
            printf("NO\n");
            continue;
        }
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for(int i = 0; i < n; i++){
            cnt1[s1[i]-'a']++;
            cnt2[s2[i]-'a']++;
        }
        int ans = 1;
        for(int i = 0; i < 26; i++){
            if(cnt1[i] != cnt2[i]){
                ans = 0;
                break;
            }
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
