#include<stdio.h>
void hanoi(char, char, char, int);
int main(void){
    int n;
    scanf("%d", &n);
    hanoi('A', 'C', 'B', n);
    return 0;
}
void hanoi(char a, char b, char c, int n){
    if(n == 1) printf("move disk %d from rod %c to rod %c\n", n, a, b);
    else{
        hanoi(a, c, b, n-1);
        printf("move disk %d from rod %c to rod %c\n", n, a, b);
        hanoi(c, b, a, n-1);
    }
}
