#include<stdio.h>
long long len[55];
long long id;
void solve(int k, int l, int r){
    if(k == 0 || id > r) return;

    if(id>=l && id<=r) printf("O");
    id++;

    if(id > r) return;
    if(id+len[k-1] < l) id += len[k-1];
    else solve(k-1, l, r);

    if(id>=l && id<=r) printf("u");
    id++;

    if(id > r) return;
    if(id+len[k-1] < l) id += len[k-1];
    else solve(k-1, l, r);

    if(id>=l && id<=r) printf("Q");
    id++;
}
int main(void){
    int k, l, r;
    for(int i = 1; i <= 50; i++)
        len[i] = 3+2*len[i-1];
    while(scanf("%d %d %d", &k, &l, &r) != EOF){
        id = 0;
        solve(k, l, r);
        printf("\n");
    }
    return 0;
}