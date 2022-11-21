#include<stdio.h>
int main(void){
	int X, Y, Z;
	scanf("%d %d %d", &X, &Y, &Z);
	printf("%d %d %d\n", (X-Y+Z)/2, (X+Y-Z)/2, (-X+Y+Z)/2);
	return 0;
}