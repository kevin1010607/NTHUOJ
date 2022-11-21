#include<stdio.h>
char s[105];
long long solve(int first, int last){
    if(first+1 == last) return 1;
    else{
        int sum = 0;
        for(int i = first; i < last; i++){
            if(s[i] == '(') sum++;
            if(s[i] == ')') sum--;
            if(sum == 0) return solve(first, i)+solve(i+1, last);
        }
        return 2*solve(first+1, last-1);
    }
}
int main(void){
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    printf("%lld\n", solve(0, n-1));
    return 0;
}