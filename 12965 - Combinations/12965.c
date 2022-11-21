#include<stdio.h>
void solve(int, int, int);
void display();
int arr[25], ans[25];
int n, m;
int main(void){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    solve(1, n-(m-1), m);
    return 0;
}
void solve(int p, int q, int k){
    if(k == 0)display();
    else{
        for(int i = p; i <= q; i++){
            ans[m-k] = arr[i];
            solve(i+1, n-(k-2), k-1);
        }
    }
}
void display(){
    for(int i = 0; i < m; i++)
        if(i != m-1) printf("%d ", ans[i]);
        else printf("%d\n", ans[i]);
}
