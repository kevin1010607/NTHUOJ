#include<stdio.h>
char arr[2200][2200];
void base(int len){
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++)
            arr[i][j] = '.';
        arr[i][len] = '\0';
    }
}
void display(int len){
    for(int i = 0; i < len; i++)
        printf("%s\n", arr[i]);
}
int pow(int n, int k){
    int ans = 1;
    if(k == 1) ans = n;
    else if(k%2 == 0) ans = pow(n, k/2)*pow(n, k/2);
    else if(k%2 == 1) ans = n*pow(n, k/2)*pow(n, k/2);
    return ans;
}
void solve(int p, int q, int len){
    if(len == 1) arr[p][q] = '#';
    else{
        for(int i = p; i < p+len; i += len/3)
            for(int j = q; j < q+len; j += len/3)
                if((i-p+j-q)%2 == 0)
                    solve(i, j, len/3);
    }
}
int main(void){
    int n;
    scanf("%d", &n);
    int len = pow(3, n);
    base(len);
    solve(0, 0, len);
    display(len);
    return 0;
}
