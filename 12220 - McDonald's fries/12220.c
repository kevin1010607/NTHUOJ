#include<stdio.h>
long long a[1000005];
int start;
long long max;
int Search(long long num, int start, int end){
    if(end-start <= 1){
        if(num <= a[start]) return start;
        else if(num <= a[end]) return end;
        else return -1;
    }
    int mid = start+(end-start)/2;
    if(num <= a[mid]) return Search(num, start, mid);
    else return Search(num, mid , end);
}
int main(void){
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    start = k+1, max = a[n];
    while(q--){
        long long f;
        scanf("%lld", &f);
        if(max < f) printf("gan ni nya sai bau\n");
        else{ 
            int ans = Search(f, 1, n);
            if(a[ans] == a[start]) ans = start;
            else{
                while(a[(ans-1+n-1)%n+1] == a[ans]){
                    if(ans != start) ans = (ans-1+n-1)%n+1;
                    else break;
                }
            }
            printf("%d\n", (ans-start+n)%n+1);
        }
    }
    return 0;
}
