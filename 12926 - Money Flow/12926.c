#include<stdio.h>
#include<string.h>
double money[505];
double tmp[505];
double rate[505][505];
int bankrupted[505];
int main(void){
    int n, T;
    scanf("%d %d", &n, &T);
    for(int i = 0; i < n; i++)
        scanf("%lf", &money[i]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%lf", &rate[j][i]);
    for(int t = 0; t < T; t++){
        for(int i = 0; i < n; i++){
            if(money[i] < 10 && !bankrupted[i]){
                bankrupted[i] = 1;
                for(int j = 0; j < n; j++){
                    if(i == j) continue;
                    rate[j][i] = 0;
                    rate[j][j] += rate[i][j];
                    rate[i][j] = 0;
                }
                rate[i][i] = 1;
            }
        }
        memcpy(tmp, money, sizeof(tmp));
        for(int i = 0; i < n; i++){
            money[i] = tmp[0]*rate[i][0];
            for(int j = 1; j < n; j++)
                money[i] += tmp[j]*rate[i][j];
        }
    }
    for(int i = 0; i < n; i++)
        printf("%.1lf\n", money[i]);
    return 0;
}
