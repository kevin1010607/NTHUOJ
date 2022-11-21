#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
typedef struct{
    long long sum;
    int max, len, sel;
    int *ptr;
}Group;
Group g[2005];
void create_g(Group* g){
    g->max = g->sum = g->sel = 0;
    scanf("%d", &(g->len));
    g->ptr = (int*)malloc((g->len)*sizeof(int));
    for(int i = 0; i < g->len; i++){
        scanf("%d", (g->ptr)+i);
        g->sum += (g->ptr)[i];
        g->max = max(g->max, (g->ptr)[i]);
    }
}
int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            create_g(&g[i]);
        for(int i = 0; i < n; i++){
            int idx = -1;
            for(int j = 0; j < n; j++){
                if(g[j].sel == 1) continue;
                if(idx == -1) idx = j;
                else if(g[j].sum > g[idx].sum) idx = j;
                else if(g[j].sum == g[idx].sum && g[j].max > g[idx].max) idx = j;
                else if(g[j].sum == g[idx].sum && g[j].max == g[idx].max && g[j].len > g[idx].len) idx = j;
            }
            g[idx].sel = 1;
            for(int k = 0; k < g[idx].len; k++){
                if(k != g[idx].len-1) printf("%d ", (g[idx].ptr)[k]);
                else printf("%d\n", (g[idx].ptr)[k]);
            }
        }
        for(int i = 0; i < n; i++)
            free(g[i].ptr);
    }
    return 0;
}