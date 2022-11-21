#include<stdio.h>
#define maxn 1005
long long get(char *s, int l, int r)
{
    long long ans = 0;
    for(int i = l; i <= r; i++){
        ans = 10*ans+s[i]-'0';
        s[i] = '@';
    }
    return ans;
}
int main(void){
    int n;
    scanf("%d", &n);
    char s[maxn];
    scanf("%s", s);

    int q;
    scanf("%d", &q);
    while(q--){
        int a, b, sz;
        scanf("%d %d %d", &a, &b, &sz);
        long long A = get(s, a, a+sz-1);
        long long B = get(s, b, b+sz-1);
        printf("%lld\n", A*B);
        int idx = 0;
        for(int i = 0; i < n; i++)
            if(s[i] != '@') s[idx++] = s[i];
        n -= (2*sz);
    }
    return 0;
}
