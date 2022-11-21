#include<stdio.h>
#include<stdlib.h>
int s[15];
int partition(int idx, int n, int k, int cur_sum, int target, int *used){
    if(k == 1) return 1;
    if(cur_sum > target) return 0;
    if(cur_sum == target) return partition(0, n, k-1, 0, target, used);
    else{
        for(int i = idx; i < n; i++){
            if(used[i] == 0){
                used[i] = 1;
                if(partition(i+1, n, k, cur_sum+s[i], target, used))
                    return 1;
                used[i] = 0;
            }
        }
        return 0;
    }
    return 0;
}
int main(void){
    int q;
    scanf("%d", &q);
    while(q--){
        int n, k;
        scanf("%d %d", &n, &k);
        int sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &s[i]);
            sum += s[i];
        }
        int ans;
        int *used = (int*)calloc(n, sizeof(int));
        if(sum%k == 0) ans = partition(0, n, k, 0, sum/k, used);
        else ans = 0;
        free(used);
        if(ans) printf("True\n");
        else printf("False\n");
    }
    return 0;
}
