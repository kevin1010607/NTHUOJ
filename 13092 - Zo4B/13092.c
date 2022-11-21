#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print(int ans[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(j != 3) printf("%d ", ans[i][j]);
            else printf("%d\n", ans[i][j]);
        }
    }
}
void rotate(int ans[][4], int times){
    int tmp[4][4];
    while(times--){
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                tmp[j][3-i] = ans[i][j];
        memcpy(ans, tmp, sizeof(tmp));
    }
}

void moveUp(int ans[][4]){
    for(int j = 0; j < 4; j++){
        int idx = 1;
        for(int i = 1; i < 4; i++){
            if(ans[i][j] == 0) continue;
            if(ans[idx-1][j] == 0){
                ans[idx-1][j] = ans[i][j];
                ans[i][j] = 0;
                idx--;
            }
            else if(ans[idx-1][j] == ans[i][j]){
                ans[idx-1][j] *= 2;
                ans[i][j] = 0;
            }
            else if(i != idx){
                ans[idx][j] = ans[i][j];
                ans[i][j] = 0;
            }
            idx++;
        }
    }
}
int main(void){
    int board[4][4], ans[4][4];
    while(scanf("%d %d %d %d", &board[0][0], &board[0][1], &board[0][2], &board[0][3]) != EOF){
        for(int i = 1; i < 4; i++)
            for(int j = 0; j < 4; j++)
                scanf("%d", &board[i][j]);
        int dir[] = {0, 2, 1, 3};
        for(int d = 0; d < 4; d++){
            memcpy(ans, board, sizeof(ans));
            rotate(ans, dir[d]);
            moveUp(ans);
            rotate(ans, 4-dir[d]);
            int same = 1;
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    if(ans[i][j] != board[i][j])
                        same = 0;
            if(same) printf("Invalid\n");
            else print(ans);
        }

    }
    return 0;
}