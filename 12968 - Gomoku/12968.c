#include<stdio.h>
#define n 15
char s[20][20];
void solve();
int main(void){
    int q;
    scanf("%d", &q);
    while(q--){
        for(int i = 0; i < n; i++)
            scanf("%s", s[i]);
        solve();
    }
    return 0;
}
void solve(){
    char win = 'n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] != '.'){
                if(i+4 < n && s[i][j] == s[i+1][j] && s[i][j] == s[i+2][j] && s[i][j] == s[i+3][j] && s[i][j] == s[i+4][j])
                    win = s[i][j];
                else if(j+4 < n && s[i][j] == s[i][j+1] && s[i][j] == s[i][j+2] && s[i][j] == s[i][j+3] && s[i][j] == s[i][j+4])
                    win = s[i][j];
                else if(i+4 < n && j+4 < n && s[i][j] == s[i+1][j+1] && s[i][j] == s[i+2][j+2] && s[i][j] == s[i+3][j+3] && s[i][j] == s[i+4][j+4])
                    win = s[i][j];
                else if(i+4 < n && j-4 >= 0 && s[i][j] == s[i+1][j-1] &&s[i][j] == s[i+2][j-2] && s[i][j] == s[i+3][j-3] && s[i][j] == s[i+4][j-4])
                    win = s[i][j];
            }
        }
    }
    if(win == 'b') printf("black\n");
    else if(win == 'w') printf("white\n");
    else printf("none\n");
}
