#include<stdio.h>
int main(void){
    //Input
    int len[2];
    int big_num[2][100] = {};
    scanf("%d", &len[0]);
    getchar();
    for(int i = len[0]-1; i >= 0; i--)
        big_num[0][i] = getchar()-'0';
    getchar();
    scanf("%d", &len[1]);
    getchar();
    for(int i = len[1]-1; i >= 0; i--)
        big_num[1][i] = getchar()-'0';

    //Compare
    int first = 0, second = 1;
    int negative = 0;
    if(len[0] < len[1]){
        first = 1, second = 0;
        negative = 1;
    }
    else if(len[0] == len[1]){
        for(int i = len[0]-1; i >= 0; i--){
            if(big_num[0][i] < big_num[1][i]){
                first = 1, second = 0;
                negative = 1;
                break;
            }
            else if(big_num[0][i] > big_num[1][i])
                break;
        }
    }

    //Subtraction
    for(int i = 0; i < len[first]; i++)
    {
        big_num[first][i] = big_num[first][i]-big_num[second][i];
        if(big_num[first][i] < 0){
            big_num[first][i] += 10;
            big_num[first][i+1]--;
        }
    }
    int result_len = len[first];
    for(int i = len[first]-1; i >= 0 && big_num[first][i] == 0; i--)
        result_len--;
    if(result_len == 0) result_len = 1;

    //Print
    if(negative) printf("-");
    for(int i = result_len-1; i >= 0; i--)
        printf("%d", big_num[first][i]);
    return 0;
}
