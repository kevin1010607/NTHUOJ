#include<stdio.h>
int row[50][50], col[50][50];
int num_row[50], num_col[50];
int tmp[50];
char s[50][50];
int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%d", &num_row[i]);
            for(int j = 0; j < num_row[i]; j++)
                scanf("%d", &row[i][j]);
        }
        for(int i = 0; i < m; i++){
            scanf("%d", &num_col[i]);
            for(int j = 0; j < num_col[i]; j++)
                scanf("%d", &col[i][j]);
        }
        for(int i = 0; i < n; i++)
            scanf("%s", s[i]);
        int ans = 1;
        for(int i = 0; i < n; i++){
            if(!ans) break;
            int first = 1, ret = 0, pre = -1, idx = 0;
            for(int j = 0; j < m-1; j++){
                if(s[i][j] == 'x') continue;
                if(first){pre = j, ret = 1, first = 0;}
                else{
                    if(pre+1 == j){pre = j, ret++;}
                    else{tmp[idx++] = ret, pre = j, ret = 1;}
                }
            }
            if(s[i][m-1] == 'o'){
                if(pre+1 == m-1) tmp[idx++] = ret+1;
                else{
                    if(!first) tmp[idx++] = ret;
                    tmp[idx++] = 1;
                }
            }
            else if(!first) tmp[idx++] = ret;
            if(idx != num_row[i]) ans = 0;
            else
                for(int j = 0; j < idx; j++)
                    if(row[i][j] != tmp[j]){ans = 0; break;}
        }
        for(int j = 0; j < m; j++){
            if(!ans) break;
            int first = 1, ret = 0, pre = -1, idx = 0;
            for(int i = 0; i < n-1; i++){
                if(s[i][j] == 'x') continue;
                if(first){pre = i, ret = 1, first = 0;}
                else{
                    if(pre+1 == i){pre = i, ret++;}
                    else{tmp[idx++] = ret, pre = i, ret = 1;}
                }
            }
            if(s[n-1][j] == 'o'){
                if(pre+1 == n-1) tmp[idx++] = ret+1;
                else{
                    if(!first) tmp[idx++] = ret;
                    tmp[idx++] = 1;
                }
            }
            else if(!first) tmp[idx++] = ret;
            if(idx != num_col[j]) ans = 0;
            else
                for(int i = 0; i < idx; i++)
                    if(col[j][i] != tmp[i]){ans = 0; break;}
        }
        if(ans) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}