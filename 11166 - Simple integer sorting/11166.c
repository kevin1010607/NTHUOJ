#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
	const int *ia = (const int*)a;
	const int *ib = (const int*)b;
	return (*ia>*ib)-(*ia<*ib);
}
int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int *arr = (int*)malloc(n*sizeof(int));
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		qsort(arr, n, sizeof(int), cmp);
		for(int i = 0; i < n-1; i++)
			printf("%d ", arr[i]);
		printf("%d\n", arr[n-1]);
		free(arr);
	}
	return 0;
}