#include<stdio.h>
#define maxn 1005
int main(void){
    int m, n, K;
    scanf("%d %d %d", &m, &n, &K);
    int A[maxn][maxn] = {};
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    while(K--){
        int a, r1, r2;
        scanf("%d %d %d", &a, &r1, &r2);
        if(a){
            for(int i = 0; i < n; i++)
                A[r1][i] = A[r1][i]+A[r2][i];
        }
        else{
            for(int i = 0; i < n; i++){
                int temp = A[r1][i];
                A[r1][i] = A[r2][i];
                A[r2][i] = temp;
            }
        }
    }

    int v[maxn] = {};
    int max = 0;
    int index = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            v[i] += (A[i][j]*A[i][j]);
        if(v[i] > max){
            max = v[i];
            index = i;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(i != n-1) printf("%d ", A[index][i]);
        else printf("%d\n", A[index][i]);
    }

    return 0;
}

