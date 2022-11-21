#include<stdio.h>
void generate(int, int, int);
void base(int);
int pow(int, int);
char arr[2200][2200];
int main(void){
    int n;
    scanf("%d", &n);
    int len = pow(3, n);
    base(len);
    generate(len, 0, 0);
    for(int i = 0; i < len; i++)
        printf("%s\n", arr[i]);
    return 0;
}
void generate(int len, int p, int q){
    if(len != 3)
        for(int oi = p; oi < p+len; oi += len/3)
            for(int oj = q; oj < q+len; oj += len/3){
                for(int i = oi+len/9; i < oi+len/9*2; i++)
                    for(int j = oj+len/9; j < oj+len/9*2; j++)
                        arr[i][j] = '#';
                generate(len/3, oi, oj);
            }
}
void base(int len){
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++)
            arr[i][j] = '.';
        arr[i][len] = '\0';
    }
    for(int i = len/3; i < len/3*2; i++)
        for(int j = len/3; j < len/3*2; j++)
            arr[i][j] = '#';
}
int pow(int n, int k){
    int ans = 1;
    if(k == 1)
        ans = n;
    else if(k%2 == 1)
        ans = n*pow(n, k/2)*pow(n, k/2);
    else if(k%2 == 0)
        ans = pow(n,k/2)*pow(n, k/2);
    return ans;
}
