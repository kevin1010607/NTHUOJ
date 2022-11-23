#include<stdio.h>
char s[15][15];
int sol = 1, valid = 1;
int row[9][10], col[9][10], block[9][10];
int main(void){
    for(int i = 0; i < 13; i++){
        scanf("%s", s[i]);
        if(i%4 == 0) continue;
        for(int j = 0; j < 13; j++){
            if(j%4 == 0) continue;
            if(sol){
                if(s[i][j] == 'x') sol = 0;
            }
            if(valid){
                if(s[i][j] != 'x'){
                    if(row[i][s[i][j]-'0'] == 1) valid = 0;
                    else row[i][s[i][j]-'0'] = 1;
                    if(col[j][s[i][j]-'0'] == 1) valid = 0;
                    else col[j][s[i][j]-'0'] = 1;
                    if(block[3*(i/4)+(j/4)][s[i][j]-'0'] == 1) valid = 0;
                    else block[3*(i/4)+(j/4)][s[i][j]-'0'] = 1;
                }
            }
        }
    }
    if(sol) printf("solution, ");
    else printf("question, ");
    if(valid) printf("valid\n");
    else printf("invalid\n");
    return 0;
}
