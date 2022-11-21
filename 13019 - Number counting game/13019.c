#include<stdio.h>
#include<stdlib.h>
int solve(int n, int k, int state, char* state_mem){
    if(state_mem[state] != 0)
        return (state_mem[state] == 1);
    for(int i = 0; i < n; i++){
        if(state & (1<<i)) continue;
        if((i+1) >= k || !solve(n, k-(i+1), state | (1<<i), state_mem)){
            state_mem[state] = 1;
            return 1;
        }
    }
    state_mem[state] = -1;
    return 0;
}
int main(void){
    int q;
    scanf("%d", &q);
    int n, k;
    while(q--){
        scanf("%d %d", &n, &k);
        char *state_mem = (char*)calloc(1<<n, sizeof(char));
        if(solve(n, k, 0, state_mem)) printf("True\n");
        else printf("False\n");
		free(state_mem);
    }
    return 0;
}