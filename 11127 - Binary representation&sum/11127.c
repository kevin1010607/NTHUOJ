#include<stdio.h>
#define maxn 11
int main(void){
    int b_a[maxn] = {};
    int b_1[maxn] = {};
    b_1[0] = 1;

    int a;
    scanf("%d", &a);
    int len;
    int flag = 1;
    for(int i = 0; ; i++)
    {
        int r = a%2;
        b_a[i] = r;
        a /= 2;
        if(b_a[i] == 0) flag = 0;
        if(a == 1 || a == 0){
            b_a[i+1] = a;
            len = i+a;
            if(a == 0) flag = 0;
            break;
        }
    }
    if(flag) len++;

    int ans[maxn] = {};
    int carry = 0;
    for(int i = 0; i < maxn; i++){
        ans[i] += b_a[i]+b_1[i];
        if(ans[i] >= 2){
            ans[i] -= 2;
            ans[i+1]++;
            carry++;
        }
    }

    for(int i = len; i >= 0; i--)
        printf("%d", ans[i]);
    printf(" %d", carry);

    return 0;
}
