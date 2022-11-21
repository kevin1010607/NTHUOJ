#include<stdio.h>

int main(void)
{
    //Input
    int len[2];
    int big_num[2][105] = {};
    scanf("%d", &len[0]);
    getchar();
    for(int i = len[0]-1; i >= 0; i--)
        big_num[0][i] = getchar()-'0';
    getchar();
    scanf("%d", &len[1]);
    getchar();
    for(int i = len[1]-1; i >= 0; i--)
        big_num[1][i] = getchar()-'0';

    //Addition
    for(int i = 0; i <= len[0] || i <= len[1]; i++)
    {
        big_num[0][i] = big_num[0][i]+big_num[1][i];
        if(big_num[0][i] >= 10)
        {
            big_num[0][i] -= 10;
            big_num[0][i+1]++;
        }
    }
    int result_len = 105;
    for(int i = 104; i >= 0 && big_num[0][i] == 0; i--)
        result_len--;
    if(result_len == 0) result_len = 1;

    //Print
    for(int i = result_len-1; i >= 0; i--)
        printf("%d", big_num[0][i]);

    return 0;
}
