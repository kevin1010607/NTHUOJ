#include<stdio.h>
int main(void){
    int arr[2] = {};
    int len[5] = {30*24*60*60, 24*60*60, 60*60, 60, 1};
    for(int i = 0; i < 2; i++){
        int val[5];
        scanf("%d/%d %d:%d:%d", &val[0], &val[1], &val[2], &val[3], &val[4]);
        for(int j = 0; j < 5; j++)
            arr[i] += len[j]*val[j];
    }
    int ans[5];
    int diff = arr[0] > arr[1] ? arr[0]-arr[1] : arr[1]-arr[0];
    for(int i = 0; i < 5; i++){
        ans[i] = diff/len[i];
        diff %= len[i];
    }
    printf("%d %d\n", ans[0], ans[1]);
    printf("%02d:%02d:%02d\n", ans[2], ans[3], ans[4]);
    return 0;
}
