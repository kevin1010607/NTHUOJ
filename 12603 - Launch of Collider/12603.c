#include<stdio.h>
char dir[200005];
int main(void){
    int n, ans = -1;
    int pre, now;
    scanf("%d", &n);
    scanf("%s", dir);
    scanf("%d", &pre);
    for(int i = 1; i < n; i++){
        scanf("%d", &now);
        if(dir[i-1]=='R' && dir[i]=='L'){
            int tmp = now-pre;
            if(ans==-1 || tmp<ans) ans = tmp;
        }
        pre = now;
    }
    printf("%d\n", (ans==-1?ans:ans/2));
    return 0;
}