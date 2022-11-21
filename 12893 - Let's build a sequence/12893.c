#include<stdio.h>
#define maxn 205
int main(void){
    int p[maxn];
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= 3; i++)
        scanf("%d", &p[i]);
    int d = (p[3]-p[2])-(p[2]-p[1]);

    for(int i = 4; i <= N; i++)
        p[i] = p[i-1]+(p[i-1]-p[i-2]+d);

    for(int i = 1; i <=N; i++){
        if(i != N) printf("%d ", p[i]);
        else printf("%d\n", p[i]);
    }
    return 0;
}
